from kalkulator import tambah, kurang, kali, bagi, akses_list, konversi_ke_int, palindrome, keliling_persegi

print("Menjalankan fungsi tanpa pengujian otomatis...\n")

print("Tambah 2 + 3 =", tambah(2, 3))
print("Kurang 10 - 4 =", kurang(10, 4))
print("Kali 3 * 3 =", kali(3, 3))

# Ini akan menyebabkan ZeroDivisionError
print("Bagi 10 / 2 =", bagi(10, 2))
print("Bagi 5 / 0 =", bagi(5, 0))  # Program crash di sini jika tidak ditangkap

# Ini akan menyebabkan IndexError
data = [1, 2, 3]
print("Akses list index 1:", akses_list(data, 1))
print("Akses list index 10:", akses_list(data, 10))  # Crash

# Ini akan menyebabkan ValueError
print("Konversi '42' ke integer:", konversi_ke_int("42"))
print("Konversi 'hello' ke integer:", konversi_ke_int("hello"))  # Crash

# Ini akan menyebabkan TypeError
print("Apakah 123 palindrome?", palindrome(123))  # Crash

# Ini akan menyebabkan ValueError
print("Keliling persegi dengan sisi 4:", keliling_persegi(4))
print("Keliling persegi dengan sisi -3:", keliling_persegi(-3))  # Crash

print("\nSelesai menjalankan fungsi!")
