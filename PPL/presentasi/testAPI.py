from flask import Flask, request, jsonify
import time

app = Flask(__name__)

@app.route('/real-time-test', methods=['POST'])
def real_time_test():
    start_time = time.time()
    data = request.json
    response_data = {
        "message": "Data diterima",
        "received_data": data,
        "timestamp": time.time()
    }
    end_time = time.time()
    response_data["response_time"] = end_time - start_time  # Hitung waktu respons
    return jsonify(response_data)

if __name__ == '__main__':
    app.run(debug=True, port=5000)