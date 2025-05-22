# app.py
from flask import Flask, render_template, request, redirect, url_for, flash, session
from flask_sqlalchemy import SQLAlchemy
from werkzeug.security import generate_password_hash, check_password_hash
from datetime import datetime, timedelta
import os

app = Flask(__name__)
app.config['SECRET_KEY'] = 'perpustakaan_rahasia'
app.config['SQLALCHEMY_DATABASE_URI'] = 'sqlite:///library.db'
app.config['SQLALCHEMY_TRACK_MODIFICATIONS'] = False

db = SQLAlchemy(app)

# Kelas Person (Base Class) - contoh penerapan konsep "Class"
class Person:
    def __init__(self, name, email, phone):
        self.name = name
        self.email = email
        self.phone = phone
    
    def display_info(self):
        return f"Nama: {self.name}, Email: {self.email}, Telepon: {self.phone}"

# Kelas User - contoh penerapan konsep "Inheritance"
class User(db.Model):
    id = db.Column(db.Integer, primary_key=True)
    username = db.Column(db.String(80), unique=True, nullable=False)
    password_hash = db.Column(db.String(128), nullable=False)
    role = db.Column(db.String(20), default='member')
    
    # Metode setter dan getter - contoh penerapan konsep "Encapsulation"
    def set_password(self, password):
        self.password_hash = generate_password_hash(password)
        
    def check_password(self, password):
        return check_password_hash(self.password_hash, password)
    
    def __repr__(self):
        return f'<User {self.username}>'

# Kelas Member - contoh lanjutan "Inheritance"
class Member(User):
    __tablename__ = 'member'
    
    id = db.Column(db.Integer, db.ForeignKey('user.id'), primary_key=True)
    name = db.Column(db.String(100), nullable=False)
    email = db.Column(db.String(100), nullable=False)
    phone = db.Column(db.String(20))
    join_date = db.Column(db.DateTime, default=datetime.utcnow)
    
    # Relationship - contoh penerapan konsep "Association"
    loans = db.relationship('Loan', backref='member', lazy=True)
    
    def __init__(self, username, password, name, email, phone):
        super().__init__()  # Ini akan memanggil konstruktor kelas User
        self.username = username
        self.set_password(password)
        self.name = name
        self.email = email
        self.phone = phone
        self.role = 'member'
    
    def is_active_member(self):
        return (datetime.utcnow() - self.join_date).days < 365
    
    def __repr__(self):
        return f'<Member {self.name}>'

# Kelas Librarian - contoh lanjutan "Inheritance" dan "Polymorphism"
class Librarian(User):
    __tablename__ = 'librarian'
    
    id = db.Column(db.Integer, db.ForeignKey('user.id'), primary_key=True)
    name = db.Column(db.String(100), nullable=False)
    email = db.Column(db.String(100), nullable=False)
    staff_id = db.Column(db.String(20), unique=True, nullable=False)
    
    def __init__(self, username, password, name, email, staff_id):
        super().__init__()
        self.username = username
        self.set_password(password)
        self.name = name
        self.email = email
        self.staff_id = staff_id
        self.role = 'librarian'
    
    # Contoh "Polymorphism" - metode dengan nama sama tapi implementasi berbeda
    def is_active_member(self):
        return True  # Librarian selalu dianggap aktif
    
    def __repr__(self):
        return f'<Librarian {self.name}>'

# Kelas Book - contoh dasar "Class" dan "Object"
class Book(db.Model):
    id = db.Column(db.Integer, primary_key=True)
    title = db.Column(db.String(200), nullable=False)
    author = db.Column(db.String(100), nullable=False)
    isbn = db.Column(db.String(20), unique=True, nullable=False)
    published_year = db.Column(db.Integer)
    quantity = db.Column(db.Integer, default=1)
    available = db.Column(db.Integer, default=1)
    
    # Relationship - contoh penerapan konsep "Association"
    category_id = db.Column(db.Integer, db.ForeignKey('category.id'))
    loans = db.relationship('Loan', backref='book', lazy=True)
    
    def __repr__(self):
        return f'<Book {self.title}>'
    
    # Metode untuk mengecek ketersediaan buku
    def is_available(self):
        return self.available > 0

# Kelas Category - contoh "Aggregation"
class Category(db.Model):
    id = db.Column(db.Integer, primary_key=True)
    name = db.Column(db.String(50), nullable=False)
    description = db.Column(db.String(200))
    
    # Relationship - contoh penerapan konsep "Aggregation"
    # Buku dapat ada di beberapa kategori, dan kategori dapat dihapus tanpa menghapus buku
    books = db.relationship('Book', backref='category', lazy=True)
    
    def __repr__(self):
        return f'<Category {self.name}>'

# Kelas Loan - contoh "Composition"
class Loan(db.Model):
    id = db.Column(db.Integer, primary_key=True)
    loan_date = db.Column(db.DateTime, default=datetime.utcnow)
    return_date = db.Column(db.DateTime, nullable=True)
    due_date = db.Column(db.DateTime, nullable=False)
    
    # Relationship - contoh penerapan konsep "Composition"
    # Peminjaman tidak dapat ada tanpa buku dan anggota
    book_id = db.Column(db.Integer, db.ForeignKey('book.id'), nullable=False)
    member_id = db.Column(db.Integer, db.ForeignKey('member.id'), nullable=False)
    
    def __init__(self, book_id, member_id):
        self.book_id = book_id
        self.member_id = member_id
        self.due_date = datetime.utcnow() + timedelta(days=14)  # Peminjaman untuk 14 hari
    
    def is_overdue(self):
        if self.return_date:
            return self.return_date > self.due_date
        return datetime.utcnow() > self.due_date
    
    def calculate_fine(self):
        if not self.is_overdue():
            return 0
        
        if self.return_date:
            days_overdue = (self.return_date - self.due_date).days
        else:
            days_overdue = (datetime.utcnow() - self.due_date).days
        
        return max(0, days_overdue) * 1000  # Denda Rp1000 per hari
    
    def __repr__(self):
        return f'<Loan {self.id}>'

# Route untuk halaman utama
@app.route('/')
def index():
    books = Book.query.all()
    return render_template('index.html', books=books)

# Route untuk login
@app.route('/login', methods=['GET', 'POST'])
def login():
    if request.method == 'POST':
        username = request.form.get('username')
        password = request.form.get('password')
        
        user = User.query.filter_by(username=username).first()
        
        if user and user.check_password(password):
            session['user_id'] = user.id
            session['role'] = user.role
            flash('Login berhasil!', 'success')
            return redirect(url_for('index'))
        else:
            flash('Username atau password salah', 'danger')
    
    return render_template('login.html')

# Route untuk logout
@app.route('/logout')
def logout():
    session.pop('user_id', None)
    session.pop('role', None)
    flash('Anda telah logout', 'info')
    return redirect(url_for('index'))

# Route untuk menampilkan semua buku
@app.route('/books')
def books():
    all_books = Book.query.all()
    return render_template('books.html', books=all_books)

# Route untuk meminjam buku
@app.route('/borrow/<int:book_id>', methods=['POST'])
def borrow_book(book_id):
    if 'user_id' not in session:
        flash('Silakan login terlebih dahulu', 'warning')
        return redirect(url_for('login'))
    
    book = Book.query.get_or_404(book_id)
    
    if book.available <= 0:
        flash('Buku tidak tersedia untuk dipinjam', 'danger')
        return redirect(url_for('books'))
    
    # Buat peminjaman baru
    loan = Loan(book_id=book.id, member_id=session['user_id'])
    
    # Kurangi jumlah buku yang tersedia
    book.available -= 1
    
    db.session.add(loan)
    db.session.commit()
    
    flash(f'Anda telah meminjam buku "{book.title}"', 'success')
    return redirect(url_for('books'))

# Route untuk mengembalikan buku
@app.route('/return/<int:loan_id>', methods=['POST'])
def return_book(loan_id):
    if 'user_id' not in session:
        flash('Silakan login terlebih dahulu', 'warning')
        return redirect(url_for('login'))
    
    loan = Loan.query.get_or_404(loan_id)
    
    # Pastikan yang mengembalikan adalah peminjam atau pustakawan
    if session['user_id'] != loan.member_id and session['role'] != 'librarian':
        flash('Anda tidak memiliki izin untuk mengembalikan buku ini', 'danger')
        return redirect(url_for('books'))
    
    # Set tanggal pengembalian
    loan.return_date = datetime.utcnow()
    
    # Tambah jumlah buku yang tersedia
    book = Book.query.get(loan.book_id)
    book.available += 1
    
    db.session.commit()
    
    # Hitung denda jika terlambat
    fine = loan.calculate_fine()
    if fine > 0:
        flash(f'Buku berhasil dikembalikan. Anda dikenakan denda Rp{fine} karena terlambat.', 'info')
    else:
        flash('Buku berhasil dikembalikan.', 'success')
    
    return redirect(url_for('my_loans'))

# Route untuk melihat peminjaman sendiri
@app.route('/my-loans')
def my_loans():
    if 'user_id' not in session:
        flash('Silakan login terlebih dahulu', 'warning')
        return redirect(url_for('login'))
    
    loans = Loan.query.filter_by(member_id=session['user_id']).all()
    return render_template('my_loans.html', loans=loans)

# Route admin untuk mengelola buku
@app.route('/admin/books', methods=['GET', 'POST'])
def admin_books():
    if 'role' not in session or session['role'] != 'librarian':
        flash('Anda tidak memiliki akses ke halaman ini', 'danger')
        return redirect(url_for('index'))
    
    if request.method == 'POST':
        title = request.form.get('title')
        author = request.form.get('author')
        isbn = request.form.get('isbn')
        published_year = request.form.get('published_year')
        quantity = request.form.get('quantity')
        category_id = request.form.get('category_id')
        
        book = Book(
            title=title,
            author=author,
            isbn=isbn,
            published_year=published_year,
            quantity=quantity,
            available=quantity,
            category_id=category_id
        )
        
        db.session.add(book)
        db.session.commit()
        
        flash(f'Buku "{title}" berhasil ditambahkan', 'success')
        return redirect(url_for('admin_books'))
    
    books = Book.query.all()
    categories = Category.query.all()
    return render_template('admin_books.html', books=books, categories=categories)

# Fungsi untuk inisialisasi database
def init_db():
    with app.app_context():
        db.create_all()
        
        # Cek apakah sudah ada admin
        admin = User.query.filter_by(username='admin').first()
        if not admin:
            admin = User(username='admin', role='librarian')
            admin.set_password('admin123')
            db.session.add(admin)
            
            # Tambahkan beberapa kategori
            categories = [
                Category(name='Fiksi', description='Buku-buku fiksi, novel, dll.'),
                Category(name='Non-Fiksi', description='Buku-buku non-fiksi, sejarah, dll.'),
                Category(name='Teknologi', description='Buku-buku terkait teknologi dan komputer')
            ]
            db.session.add_all(categories)
            
            # Tambahkan beberapa buku
            books = [
                Book(title='Python Programming', author='John Smith', isbn='1234567890', 
                     published_year=2020, quantity=5, available=5, category_id=3),
                Book(title='Laskar Pelangi', author='Andrea Hirata', isbn='2345678901',
                     published_year=2005, quantity=3, available=3, category_id=1),
                Book(title='Sejarah Indonesia', author='Prof. Dr. Kuntowijoyo', isbn='3456789012',
                     published_year=2010, quantity=2, available=2, category_id=2)
            ]
            db.session.add_all(books)
            
            db.session.commit()

if __name__ == '__main__':
    if not os.path.exists('instance/library.db'):
        init_db()
    app.run(debug=True)