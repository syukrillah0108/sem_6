#!/bin/bash
while true; do
    echo "========== $(date) =========="
    
    start=$(date +%s%3N) # waktu awal dalam milidetik
    response=$(curl -X POST http://localhost:1880/api/get_desa \
                   -H "Content-Type: application/json" \
                   -d @test_desa.json \
                   -s)
    end=$(date +%s%3N)   # waktu akhir dalam milidetik
    elapsed=$((end - start))

    echo "$response" | jq
    echo "Request time: ${elapsed} ms"

    sleep 1
done
