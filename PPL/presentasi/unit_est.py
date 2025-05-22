def operasi_besar():
    hasil = 10 / 2
    hasil += "20"
    return hasil

def test_operasi_besar():
    assert operasi_besar() == 15

hasil = (10 / 2) + "20"