def generate_vigenere_square():
    square = [[0 for _ in range(256)] for _ in range(256)]  # Membuat tabel 256x256 (untuk setiap karakter ASCII)

    for i in range(256):
        for j in range(256):
            # Mengisi tabel dengan operasi XOR antara nilai bit dari indeks i dan j
            square[i][j] = i ^ j

    return square


def vigenere_encrypt(plaintext, key, vigenere_square):
    ciphertext = ""
    key_length = len(key)
    key_as_int = [ord(k) for k in key]

    for i, p in enumerate(plaintext):
        # Mengonversi karakter plaintext dan key ke nilai ASCII
        plaintext_int = ord(p)
        key_int = key_as_int[i % key_length]

        # Operasi XOR menggunakan nilai dari Vigenère Square
        encrypted_char = vigenere_square[plaintext_int][key_int]
        ciphertext += chr(encrypted_char)

    return ciphertext

def vigenere_decrypt(ciphertext, key, vigenere_square):
    decrypted_text = ""
    key_length = len(key)
    key_as_int = [ord(k) for k in key]

    for i, c in enumerate(ciphertext):
        # Mengonversi karakter ciphertext dan key ke nilai ASCII
        ciphertext_int = ord(c)
        key_int = key_as_int[i % key_length]

        # Operasi XOR menggunakan nilai dari Vigenère Square
        decrypted_char = vigenere_square[key_int].index(ciphertext_int)
        decrypted_text += chr(decrypted_char)

    return decrypted_text

# Contoh penggunaan
plaintext = "HelloWorld"
key = "Key123"
vigenere_square = generate_vigenere_square()

encrypted_text = vigenere_encrypt(plaintext, key, vigenere_square)
decrypted_text = vigenere_decrypt(encrypted_text, key, vigenere_square)

print("Plaintext:", plaintext)
print("Key:", key)
print("Encrypted Text:", encrypted_text)
print("Decrypted Text:", decrypted_text)
print(vigenere_square)