def advance_vigenere_encrypt(plain_text, key):
    encrypted_text = ''
    key_length = len(key)

    for i in range(len(plain_text)):
        char = plain_text[i]
        key_char = key[i % key_length]
        encrypted_char = chr((ord(char) + ord(key_char)) % 256)
        encrypted_text += encrypted_char

    return encrypted_text

def advance_vigenere_decrypt(encrypted_text, key):
    decrypted_text = ''
    key_length = len(key)

    for i in range(len(encrypted_text)):
        char = encrypted_text[i]
        key_char = key[i % key_length]
        decrypted_char = chr((ord(char) - ord(key_char)) % 256)
        decrypted_text += decrypted_char

    return decrypted_text


# Contoh penggunaan:
nomor_mesin_handphone = input('Daftarkan nomor mesin handphone kamu: ')
key = nomor_mesin_handphone

username = input("Masukkan username: ")
password = input("Masukkan password: ")
pin = input("Masukkan pin (6digit): ")
pesan_asli = f"username: {username}\npassword: {password}\npin: {pin}"


print("Key: " + key + "\n\n==> Pesan sebelum di enkripsi: \n" + pesan_asli)

pesan_terenkripsi = advance_vigenere_encrypt(pesan_asli, key)
print("\n==> Pesan Terenkripsi yang dikirimkan user: \n" + pesan_terenkripsi)

pesan_terdekripsi = advance_vigenere_decrypt(pesan_terenkripsi, key)
print("\n==> Pesan Terdekripsi yang diterima pihak bank: \n" + pesan_terdekripsi)
