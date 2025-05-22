# Nama file CSV
output_file="hasil_benchmark.csv"

# Tambahkan header jika file belum ada
if [ ! -f "$output_file" ]; then
    echo "timestamp,elapsed_ms" >> "$output_file"
fi

while true; do
    echo "========== $(date) =========="

    start=$(date +%s%3N) # waktu awal dalam milidetik

    # Eksekusi query (ganti sesuai kebutuhanmu)
    response=$(mysql -u root --password='Syuknet@mint' -D desa -N -e "SELECT * FROM prov;")

    end=$(date +%s%3N)   # waktu akhir
    elapsed=$((end - start))

    echo "Result: $response"
    echo "Request time: ${elapsed} ms"

    # Simpan ke file CSV
    echo "$(date +%Y-%m-%dT%H:%M:%S),$elapsed" >> "$output_file"

    sleep 0.1
done
