def tambah(a, b):
    return a + b

def kurang(a, b):
    return a - b

def kali(a, b):
    return a * b

def bagi(a, b):
    """Fungsi ini akan error jika b = 0"""
    return a / b  # Jika b = 0, akan terjadi ZeroDivisionError

def akses_list(lst, index):
    """Fungsi ini akan error jika indeks di luar batas"""
    return lst[index]  # Jika indeks tidak ada dalam list, IndexError akan muncul

def konversi_ke_int(teks):
    """Fungsi ini akan error jika teks tidak bisa dikonversi ke integer"""
    return int(teks)  # Jika teks bukan angka, akan terjadi ValueError

def palindrome(kata):
    """Fungsi ini akan error jika input bukan string"""
    return kata == kata[::-1]  # Jika kata bukan string, TypeError bisa terjadi

def keliling_persegi(sisi):
    """Fungsi ini akan error jika sisi negatif"""
    if sisi < 0:
        raise ValueError("Sisi tidak boleh negatif")
    return 4 * sisi
