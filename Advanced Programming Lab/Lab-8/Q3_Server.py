import socket
PORT =  6969
sockfd = socket.socket()
host = socket.gethostname()
sockfd.bind((host,PORT))
sockfd.listen(1)

while True:
    client, addr = sockfd.accept()
    print("Connected from", addr)
    String = client.recv(1024).decode()
    length = len(String)
    if(String == String[::1]):
        client.send("String is pallindrome with length " + str(length).encode())
    else:
        client.send("String is not palindrome with length " + str(length).encode())
    client.send()
    client.close()



