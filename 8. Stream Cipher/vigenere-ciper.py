def encrypt(plaintext, key):
    ciphertext = ""
    key_stream = generate_key_stream(plaintext, key)
    
    for p, k in zip(plaintext, key_stream):
        # Konversi karakter ke representasi ASCII dan lakukan operasi XOR
        encrypted_char = chr(ord(p) ^ ord(k))
        ciphertext += encrypted_char
    
    return ciphertext

def decrypt(ciphertext, key):
    decrypted_text = ""
    key_stream = generate_key_stream(ciphertext, key)
    
    for c, k in zip(ciphertext, key_stream):
        # Konversi karakter ke representasi ASCII dan lakukan operasi XOR
        decrypted_char = chr(ord(c) ^ ord(k))
        decrypted_text += decrypted_char
    
    return decrypted_text

def generate_key_stream(text, key):
    key_stream = ""
    key_length = len(key)
    
    for i in range(len(text)):
        key_stream += key[i % key_length]
    
    return key_stream

# Contoh penggunaan
plaintext = "HelloWorld"
key = "Key123"

encrypted_text = encrypt(plaintext, key)
decrypted_text = decrypt(encrypted_text, key)

print("Plaintext:", plaintext)
print("Key:", key)
print("Encrypted Text:", encrypted_text)
print("Decrypted Text:", decrypted_text)