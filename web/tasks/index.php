<?php
// config/database.php - Konfigurasi database
class Database {
    private $host = "localhost";
    private $db_name = "library_db";
    private $username = "root";
    private $password = "";
    private $conn;
    
    // Metode untuk mendapatkan koneksi - contoh encapsulation
    public function getConnection() {
        $this->conn = null;
        
        try {
            $this->conn = new PDO("mysql:host=" . $this->host . ";dbname=" . $this->db_name, $this->username, $this->password);
            $this->conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
        } catch(PDOException $e) {
            echo "Connection error: " . $e->getMessage();
        }
        
        return $this->conn;
    }
}

// models/Person.php - Kelas dasar untuk orang (Base Class)
// Contoh penerapan konsep "Class"
class Person {
    protected $name;
    protected $email;
    protected $phone;

    public function __construct($name, $email, $phone) {
        $this->name = $name;
        $this->email = $email;
        $this->phone = $phone;
    }

    // Getters & Setters - contoh encapsulation
    public function getName() {
        return $this->name;
    }

    public function setName($name) {
        $this->name = $name;
    }

    public function getEmail() {
        return $this->email;
    }

    public function setEmail($email) {
        $this->email = $email;
    }

    public function getPhone() {
        return $this->phone;
    }

    public function setPhone($phone) {
        $this->phone = $phone;
    }

    public function displayInfo() {
        return "Nama: " . $this->name . ", Email: " . $this->email . ", Telepon: " . $this->phone;
    }
}

// models/User.php - Kelas User
// Contoh penerapan konsep "Inheritance"
class User extends Person {
    protected $id;
    protected $username;
    private $password_hash;
    protected $role;

    public function __construct($name, $email, $phone, $username, $password, $role = 'member') {
        parent::__construct($name, $email, $phone);
        $this->username = $username;
        $this->setPassword($password);
        $this->role = $role;
    }

    // Encapsulation untuk password
    public function setPassword($password) {
        $this->password_hash = password_hash($password, PASSWORD_DEFAULT);
    }

    public function verifyPassword($password) {
        return password_verify($password, $this->password_hash);
    }

    public function getId() {
        return $this->id;
    }

    public function setId($id) {
        $this->id = $id;
    }

    public function getUsername() {
        return $this->username;
    }

    public function getRole() {
        return $this->role;
    }

    // Fungsi untuk menyimpan user ke database
    public function save($conn) {
        try {
            $query = "INSERT INTO users (name, email, phone, username, password_hash, role) 
                     VALUES (:name, :email, :phone, :username, :password_hash, :role)";
            
            $stmt = $conn->prepare($query);
            
            $stmt->bindParam(':name', $this->name);
            $stmt->bindParam(':email', $this->email);
            $stmt->bindParam(':phone', $this->phone);
            $stmt->bindParam(':username', $this->username);
            $stmt->bindParam(':password_hash', $this->password_hash);
            $stmt->bindParam(':role', $this->role);
            
            if($stmt->execute()) {
                $this->id = $conn->lastInsertId();
                return true;
            }
            return false;
        } catch(PDOException $e) {
            echo "Error: " . $e->getMessage();
            return false;
        }
    }

    // Fungsi untuk mengambil user berdasarkan username
    public static function findByUsername($conn, $username) {
        try {
            $query = "SELECT * FROM users WHERE username = :username";
            $stmt = $conn->prepare($query);
            $stmt->bindParam(':username', $username);
            $stmt->execute();
            
            $row = $stmt->fetch(PDO::FETCH_ASSOC);
            
            if($row) {
                $user = new User(
                    $row['name'],
                    $row['email'],
                    $row['phone'],
                    $row['username'],
                    '', // Password kosong karena sudah di-hash
                    $row['role']
                );
                $user->setId($row['id']);
                $user->password_hash = $row['password_hash'];
                
                return $user;
            }
            
            return null;
        } catch(PDOException $e) {
            echo "Error: " . $e->getMessage();
            return null;
        }
    }
}

// models/Member.php - Kelas untuk anggota perpustakaan
// Contoh lanjutan "Inheritance"
class Member extends User {
    private $join_date;
    private $loans = [];

    public function __construct($name, $email, $phone, $username, $password) {
        parent::__construct($name, $email, $phone, $username, $password, 'member');
        $this->join_date = date('Y-m-d H:i:s');
    }

    // Metode untuk mengecek apakah member aktif
    // Ini juga contoh penerapan "Polymorphism"
    public function isActiveMember() {
        $join_date = new DateTime($this->join_date);
        $now = new DateTime();
        $interval = $join_date->diff($now);
        
        return $interval->y < 1; // Aktif jika bergabung kurang dari 1 tahun
    }

    // Association: hubungan dengan Loan
    public function addLoan($loan) {
        $this->loans[] = $loan;
    }

    public function getLoans() {
        return $this->loans;
    }

    // Menyimpan member ke database
    public function save($conn) {
        if(parent::save($conn)) {
            try {
                $query = "INSERT INTO members (user_id, join_date) VALUES (:user_id, :join_date)";
                $stmt = $conn->prepare($query);
                
                $stmt->bindParam(':user_id', $this->id);
                $stmt->bindParam(':join_date', $this->join_date);
                
                return $stmt->execute();
            } catch(PDOException $e) {
                echo "Error: " . $e->getMessage();
                return false;
            }
        }
        return false;
    }

    // Mengambil member berdasarkan ID
    public static function findById($conn, $id) {
        try {
            $query = "SELECT u.*, m.join_date 
                     FROM users u
                     JOIN members m ON u.id = m.user_id
                     WHERE u.id = :id";
            
            $stmt = $conn->prepare($query);
            $stmt->bindParam(':id', $id);
            $stmt->execute();
            
            $row = $stmt->fetch(PDO::FETCH_ASSOC);
            
            if($row) {
                $member = new Member(
                    $row['name'],
                    $row['email'],
                    $row['phone'],
                    $row['username'],
                    '' // Password kosong karena sudah di-hash
                );
                $member->setId($row['id']);
                $member->password_hash = $row['password_hash'];
                $member->join_date = $row['join_date'];
                
                // Load loans
                $member->loadLoans($conn);
                
                return $member;
            }
            
            return null;
        } catch(PDOException $e) {
            echo "Error: " . $e->getMessage();
            return null;
        }
    }

    // Memuat semua peminjaman untuk member ini
    private function loadLoans($conn) {
        try {
            $query = "SELECT * FROM loans WHERE member_id = :member_id";
            $stmt = $conn->prepare($query);
            $stmt->bindParam(':member_id', $this->id);
            $stmt->execute();
            
            while($row = $stmt->fetch(PDO::FETCH_ASSOC)) {
                $loan = Loan::createFromArray($conn, $row);
                $this->loans[] = $loan;
            }
        } catch(PDOException $e) {
            echo "Error: " . $e->getMessage();
        }
    }
}

// models/Librarian.php - Kelas untuk pustakawan
// Contoh lanjutan "Inheritance" dan "Polymorphism"
class Librarian extends User {
    private $staff_id;

    public function __construct($name, $email, $phone, $username, $password, $staff_id) {
        parent::__construct($name, $email, $phone, $username, $password, 'librarian');
        $this->staff_id = $staff_id;
    }

    public function getStaffId() {
        return $this->staff_id;
    }

    // Polymorphism: implementasi berbeda dari metode isActiveMember
    public function isActiveMember() {
        return true; // Pustakawan selalu dianggap aktif
    }

    // Pustakawan dapat menambahkan buku baru
    public function addBook($conn, $book) {
        return $book->save($conn);
    }

    // Menyimpan librarian ke database
    public function save($conn) {
        if(parent::save($conn)) {
            try {
                $query = "INSERT INTO librarians (user_id, staff_id) VALUES (:user_id, :staff_id)";
                $stmt = $conn->prepare($query);
                
                $stmt->bindParam(':user_id', $this->id);
                $stmt->bindParam(':staff_id', $this->staff_id);
                
                return $stmt->execute();
            } catch(PDOException $e) {
                echo "Error: " . $e->getMessage();
                return false;
            }
        }
        return false;
    }
}

// models/Category.php - Kelas untuk kategori buku
// Contoh penerapan konsep dasar "Class" dan akan digunakan untuk "Aggregation"
class Category {
    private $id;
    private $name;
    private $description;
    private $books = []; // Ini akan menyimpan daftar buku dalam kategori ini

    public function __construct($name, $description = '') {
        $this->name = $name;
        $this->description = $description;
    }

    public function getId() {
        return $this->id;
    }

    public function setId($id) {
        $this->id = $id;
    }

    public function getName() {
        return $this->name;
    }

    public function getDescription() {
        return $this->description;
    }

    // Aggregation: Category "has-a" Book
    public function addBook($book) {
        $this->books[] = $book;
    }

    public function getBooks() {
        return $this->books;
    }

    // Menyimpan kategori ke database
    public function save($conn) {
        try {
            $query = "INSERT INTO categories (name, description) VALUES (:name, :description)";
            $stmt = $conn->prepare($query);
            
            $stmt->bindParam(':name', $this->name);
            $stmt->bindParam(':description', $this->description);
            
            if($stmt->execute()) {
                $this->id = $conn->lastInsertId();
                return true;
            }
            return false;
        } catch(PDOException $e) {
            echo "Error: " . $e->getMessage();
            return false;
        }
    }

    // Mengambil semua kategori
    public static function getAll($conn) {
        try {
            $query = "SELECT * FROM categories";
            $stmt = $conn->prepare($query);
            $stmt->execute();
            
            $categories = [];
            
            while($row = $stmt->fetch(PDO::FETCH_ASSOC)) {
                $category = new Category($row['name'], $row['description']);
                $category->setId($row['id']);
                $categories[] = $category;
            }
            
            return $categories;
        } catch(PDOException $e) {
            echo "Error: " . $e->getMessage();
            return [];
        }
    }

    // Mengambil kategori berdasarkan ID
    public static function findById($conn, $id) {
        try {
            $query = "SELECT * FROM categories WHERE id = :id";
            $stmt = $conn->prepare($query);
            $stmt->bindParam(':id', $id);
            $stmt->execute();
            
            $row = $stmt->fetch(PDO::FETCH_ASSOC);
            
            if($row) {
                $category = new Category($row['name'], $row['description']);
                $category->setId($row['id']);
                return $category;
            }
            
            return null;
        } catch(PDOException $e) {
            echo "Error: " . $e->getMessage();
            return null;
        }
    }
}

// models/Book.php - Kelas untuk buku
// Contoh dasar "Class" dan "Object" dan akan digunakan untuk "Association" dan "Aggregation"
class Book {
    private $id;
    private $title;
    private $author;
    private $isbn;
    private $published_year;
    private $quantity;
    private $available;
    private $category_id;
    private $category; // Object Category

    public function __construct($title, $author, $isbn, $published_year, $quantity, $category_id) {
        $this->title = $title;
        $this->author = $author;
        $this->isbn = $isbn;
        $this->published_year = $published_year;
        $this->quantity = $quantity;
        $this->available = $quantity; // Awalnya semua buku tersedia
        $this->category_id = $category_id;
    }

    public function getId() {
        return $this->id;
    }

    public function setId($id) {
        $this->id = $id;
    }

    public function getTitle() {
        return $this->title;
    }

    public function getAuthor() {
        return $this->author;
    }

    public function getIsbn() {
        return $this->isbn;
    }

    public function getPublishedYear() {
        return $this->published_year;
    }

    public function getQuantity() {
        return $this->quantity;
    }

    public function getAvailable() {
        return $this->available;
    }

    public function setAvailable($available) {
        $this->available = $available;
    }

    public function getCategoryId() {
        return $this->category_id;
    }

    // Association: Book "knows-a" Category
    public function setCategory($category) {
        $this->category = $category;
    }

    public function getCategory() {
        return $this->category;
    }

    // Mengecek ketersediaan buku
    public function isAvailable() {
        return $this->available > 0;
    }

    // Mengurangi jumlah buku yang tersedia saat dipinjam
    public function borrowOne() {
        if($this->isAvailable()) {
            $this->available--;
            return true;
        }
        return false;
    }

    // Menambah jumlah buku yang tersedia saat dikembalikan
    public function returnOne() {
        if($this->available < $this->quantity) {
            $this->available++;
            return true;
        }
        return false;
    }

    // Menyimpan buku ke database
    public function save($conn) {
        try {
            $query = "INSERT INTO books (title, author, isbn, published_year, quantity, available, category_id) 
                     VALUES (:title, :author, :isbn, :published_year, :quantity, :available, :category_id)";
            
            $stmt = $conn->prepare($query);
            
            $stmt->bindParam(':title', $this->title);
            $stmt->bindParam(':author', $this->author);
            $stmt->bindParam(':isbn', $this->isbn);
            $stmt->bindParam(':published_year', $this->published_year);
            $stmt->bindParam(':quantity', $this->quantity);
            $stmt->bindParam(':available', $this->available);
            $stmt->bindParam(':category_id', $this->category_id);
            
            if($stmt->execute()) {
                $this->id = $conn->lastInsertId();
                return true;
            }
            return false;
        } catch(PDOException $e) {
            echo "Error: " . $e->getMessage();
            return false;
        }
    }

    // Update buku di database
    public function update($conn) {
        try {
            $query = "UPDATE books 
                     SET title = :title, author = :author, isbn = :isbn, 
                         published_year = :published_year, quantity = :quantity, 
                         available = :available, category_id = :category_id
                     WHERE id = :id";
            
            $stmt = $conn->prepare($query);
            
            $stmt->bindParam(':title', $this->title);
            $stmt->bindParam(':author', $this->author);
            $stmt->bindParam(':isbn', $this->isbn);
            $stmt->bindParam(':published_year', $this->published_year);
            $stmt->bindParam(':quantity', $this->quantity);
            $stmt->bindParam(':available', $this->available);
            $stmt->bindParam(':category_id', $this->category_id);
            $stmt->bindParam(':id', $this->id);
            
            return $stmt->execute();
        } catch(PDOException $e) {
            echo "Error: " . $e->getMessage();
            return false;
        }
    }

    // Mengambil semua buku
    public static function getAll($conn) {
        try {
            $query = "SELECT b.*, c.name as category_name, c.description as category_description 
                     FROM books b
                     LEFT JOIN categories c ON b.category_id = c.id";
            
            $stmt = $conn->prepare($query);
            $stmt->execute();
            
            $books = [];
            
            while($row = $stmt->fetch(PDO::FETCH_ASSOC)) {
                $book = new Book(
                    $row['title'],
                    $row['author'],
                    $row['isbn'],
                    $row['published_year'],
                    $row['quantity'],
                    $row['category_id']
                );
                
                $book->setId($row['id']);
                $book->setAvailable($row['available']);
                
                // Set category jika ada
                if($row['category_id']) {
                    $category = new Category($row['category_name'], $row['category_description']);
                    $category->setId($row['category_id']);
                    $book->setCategory($category);
                }
                
                $books[] = $book;
            }
            
            return $books;
        } catch(PDOException $e) {
            echo "Error: " . $e->getMessage();
            return [];
        }
    }

    // Mengambil buku berdasarkan ID
    public static function findById($conn, $id) {
        try {
            $query = "SELECT b.*, c.name as category_name, c.description as category_description 
                     FROM books b
                     LEFT JOIN categories c ON b.category_id = c.id
                     WHERE b.id = :id";
            
            $stmt = $conn->prepare($query);
            $stmt->bindParam(':id', $id);
            $stmt->execute();
            
            $row = $stmt->fetch(PDO::FETCH_ASSOC);
            
            if($row) {
                $book = new Book(
                    $row['title'],
                    $row['author'],
                    $row['isbn'],
                    $row['published_year'],
                    $row['quantity'],
                    $row['category_id']
                );
                
                $book->setId($row['id']);
                $book->setAvailable($row['available']);
                
                // Set category jika ada
                if($row['category_id']) {
                    $category = new Category($row['category_name'], $row['category_description']);
                    $category->setId($row['category_id']);
                    $book->setCategory($category);
                }
                
                return $book;
            }
            
            return null;
        } catch(PDOException $e) {
            echo "Error: " . $e->getMessage();
            return null;
        }
    }
}

// models/Loan.php - Kelas untuk peminjaman buku
// Contoh penerapan konsep "Composition"
class Loan {
    private $id;
    private $loan_date;
    private $return_date;
    private $due_date;
    private $book_id;
    private $member_id;
    private $book; // Objek Book
    private $member; // Objek Member

    public function __construct($book_id, $member_id) {
        $this->book_id = $book_id;
        $this->member_id = $member_id;
        $this->loan_date = date('Y-m-d H:i:s');
        
        // Due date 14 hari dari sekarang
        $today = new DateTime();
        $today->modify('+14 days');
        $this->due_date = $today->format('Y-m-d H:i:s');
        
        $this->return_date = null;
    }

    public function getId() {
        return $this->id;
    }

    public function setId($id) {
        $this->id = $id;
    }

    public function getLoanDate() {
        return $this->loan_date;
    }

    public function getDueDate() {
        return $this->due_date;
    }

    public function getReturnDate() {
        return $this->return_date;
    }

    public function setReturnDate($return_date) {
        $this->return_date = $return_date;
    }

    public function getBookId() {
        return $this->book_id;
    }

    public function getMemberId() {
        return $this->member_id;
    }

    // Composition: Loan "contains-a" Book (relasi kuat)
    public function setBook($book) {
        $this->book = $book;
    }

    public function getBook() {
        return $this->book;
    }

    // Composition: Loan "contains-a" Member (relasi kuat)
    public function setMember($member) {
        $this->member = $member;
    }

    public function getMember() {
        return $this->member;
    }

    // Mengecek apakah peminjaman terlambat
    public function isOverdue() {
        $due_date = new DateTime($this->due_date);
        
        if($this->return_date) {
            $return_date = new DateTime($this->return_date);
            return $return_date > $due_date;
        } else {
            $now = new DateTime();
            return $now > $due_date;
        }
    }

    // Menghitung denda jika terlambat
    public function calculateFine() {
        if(!$this->isOverdue()) {
            return 0;
        }
        
        $due_date = new DateTime($this->due_date);
        
        if($this->return_date) {
            $return_date = new DateTime($this->return_date);
            $days_overdue = $due_date->diff($return_date)->days;
        } else {
            $now = new DateTime();
            $days_overdue = $due_date->diff($now)->days;
        }
        
        return max(0, $days_overdue) * 1000; // Rp1000 per hari
    }

    // Menyimpan peminjaman ke database
    public function save($conn) {
        try {
            $query = "INSERT INTO loans (book_id, member_id, loan_date, due_date) 
                     VALUES (:book_id, :member_id, :loan_date, :due_date)";
            
            $stmt = $conn->prepare($query);
            
            $stmt->bindParam(':book_id', $this->book_id);
            $stmt->bindParam(':member_id', $this->member_id);
            $stmt->bindParam(':loan_date', $this->loan_date);
            $stmt->bindParam(':due_date', $this->due_date);
            
            if($stmt->execute()) {
                $this->id = $conn->lastInsertId();
                
                // Update ketersediaan buku
                $book = Book::findById($conn, $this->book_id);
                if($book) {
                    $book->borrowOne();
                    $book->update($conn);
                }
                
                return true;
            }
            return false;
        } catch(PDOException $e) {
            echo "Error: " . $e->getMessage();
            return false;
        }
    }

    // Update peminjaman (untuk pengembalian)
    public function update($conn) {
        try {
            $query = "UPDATE loans SET return_date = :return_date WHERE id = :id";
            $stmt = $conn->prepare($query);
            
            $stmt->bindParam(':return_date', $this->return_date);
            $stmt->bindParam(':id', $this->id);
            
            if($stmt->execute()) {
                // Update ketersediaan buku
                $book = Book::findById($conn, $this->book_id);
                if($book) {
                    $book->returnOne();
                    $book->update($conn);
                }
                
                return true;
            }
            return false;
        } catch(PDOException $e) {
            echo "Error: " . $e->getMessage();
            return false;
        }
    }

    // Mengambil peminjaman berdasarkan ID
    public static function findById($conn, $id) {
        try {
            $query = "SELECT * FROM loans WHERE id = :id";
            $stmt = $conn->prepare($query);
            $stmt->bindParam(':id', $id);
            $stmt->execute();
            
            $row = $stmt->fetch(PDO::FETCH_ASSOC);
            
            if($row) {
                return self::createFromArray($conn, $row);
            }
            
            return null;
        } catch(PDOException $e) {
            echo "Error: " . $e->getMessage();
            return null;
        }
    }

    // Mengambil semua peminjaman untuk anggota tertentu
    public static function findByMemberId($conn, $member_id) {
        try {
            $query = "SELECT * FROM loans WHERE member_id = :member_id";
            $stmt = $conn->prepare($query);
            $stmt->bindParam(':member_id', $member_id);
            $stmt->execute();
            
            $loans = [];
            
            while($row = $stmt->fetch(PDO::FETCH_ASSOC)) {
                $loans[] = self::createFromArray($conn, $row);
            }
            
            return $loans;
        } catch(PDOException $e) {
            echo "Error: " . $e->getMessage();
            return [];
        }
    }

    // Membantu membuat objek Loan dari array data
    public static function createFromArray($conn, $data) {
        $loan = new Loan($data['book_id'], $data['member_id']);
        $loan->setId($data['id']);
        $loan->loan_date = $data['loan_date'];
        $loan->due_date = $data['due_date'];
        $loan->return_date = $data['return_date'];
        
        // Load book dan member
        $book = Book::findById($conn, $data['book_id']);
        if($book) {
            $loan->setBook($book);
        }
        
        $member = Member::findById($conn, $data['member_id']);
        if($member) {
            $loan->setMember($member);
        }
        
        return $loan;
    }
}
?>