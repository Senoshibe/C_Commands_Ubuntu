//breakdown of task1_W4.c file

// Initialize p, q, e
	BN_hex2bn(&m, "Insert your message here"); // m value in line 4 can be the plain text message or the encrypted message, depending on whether you wish to encrypt or decrypt the message.
	BN_hex2bn(&e, "010001");
	BN_hex2bn(&n, "DCBFFE3E51F62E09CE7032E2677A78946A849DC4CDDE3A4D0CB81629242FB1A5");
	BN_hex2bn(&d, "74D806F9F3A62BAE331FFE3F0A68AFE35B3D2E4794148AACBC26AA381CD7D30D");

	
//Encryption code: m^e mod n, where m = Hexidecimal string
//i.e. You encrypt the message where you'd place in "Insert your message here". The message is a plain text message that was converted to a Hexidecimal string. 
// Refer to Read.me file for text-hex conversion formula in C
	BN_mod_exp(enc, m, e, n, ctx);
	printBN("Encrypted Message = ", enc);
    
//Decryption code: m^d mod n, where m = Encrypted Message
    Bn_mod_exp(dec, m, d, n, ctx);
    printBN("Encrypted Message ="), enc);

//NOTE: In the task1_W4 file (a RSA Decryptor/Encryptor), make sure to leave either the Encryption code or the Decryption code and not both. 


//For example

//EXAMPLE 1: ENCRYPTION
//Problem: You want to encrypt the message "I love you" before sending it to your partner. Make sure to convert it to a hexi-decimal string first. Run the following code in the terminal, not the file.
    echo "I love you" | xxd -p
    49206c6f766520796f750a //Returns the hexi-decimal string 49206c6f766520796f750a

//You'll need your partner's public key - in this case (e,n) = (010001,DCBFFE3E51F62E09CE7032E2677A78946A849DC4CDDE3A4D0CB81629242FB1A5)
//NOTE: You do not know your partner's private key (d,n) and therefore the d value. The d value will be left in the code just for convenience sake.
//Edit only the below parts of the task1_W4.c file to begin the encryption

    BN_hex2bn(&m, "49206c6f766520796f750a"); //make sure to convert the plain text message "I love you" into a hexi-descimal string first. Refer to README.md file under TEXT-HEX CONVERSION
	BN_hex2bn(&e, "010001");
	BN_hex2bn(&n, "DCBFFE3E51F62E09CE7032E2677A78946A849DC4CDDE3A4D0CB81629242FB1A5");
	BN_hex2bn(&d, "74D806F9F3A62BAE331FFE3F0A68AFE35B3D2E4794148AACBC26AA381CD7D30D");

    BN_mod_exp(enc, m, e, n, ctx);
    printBN("Encrypted Message = ", enc); //save and close the file

//After making the above changes to the task1_W4.c file, create and run a runable file to return the encrypted message. Let's called the runable file 'confessions'. Run the following code in the terminal.
    gcc -o confessions task1_W4.c -lcrypto

//Now run the file
    ./confessions
    Encrypted Message =  9C03145EAA2FDDDCE0FC41B6E7803C80EA49C31AD67862C9C04EA44E701E29CC //./confessions returns the encrypted message


//EXAMPLE 2: DECRYPTION
//Problem: Your partner receives an encrypted message, and she knows the message was encrypted using her public key, as you often share secret messages using RSA encryption.
// The Encrypted Message is 9C03145EAA2FDDDCE0FC41B6E7803C80EA49C31AD67862C9C04EA44E701E29CC as shown above. This will now be the new 'm' value as we're decrypting the message.
//Your partner will need her private key to decrypt the message - in this case (d,n) = (74D806F9F3A62BAE331FFE3F0A68AFE35B3D2E4794148AACBC26AA381CD7D30D,DCBFFE3E51F62E09CE7032E2677A78946A849DC4CDDE3A4D0CB81629242FB1A5)
//Edit only the below parts of the task1_W4.c file to begin the decryption

    BN_hex2bn(&m, "9C03145EAA2FDDDCE0FC41B6E7803C80EA49C31AD67862C9C04EA44E701E29CC"); // new m is now the encrypted message 9C03145EAA2FDDDCE0FC41B6E7803C80EA49C31AD67862C9C04EA44E701E29CC
	BN_hex2bn(&e, "010001");
	BN_hex2bn(&n, "DCBFFE3E51F62E09CE7032E2677A78946A849DC4CDDE3A4D0CB81629242FB1A5");
	BN_hex2bn(&d, "74D806F9F3A62BAE331FFE3F0A68AFE35B3D2E4794148AACBC26AA381CD7D30D");

    BN_mod_exp(dec, m, d, n, ctx); //dec stands for decryption, m is the encrypted message, and replace e with d (since your partner is using her private key to decryprt the message)
    printBN("Decrypted Message = ", dec); //save and close the file

//After making the above changes to the task1_W4.c file, create and run a runable file to return the decrypted message. Let's called the runable file 'iwonderwhatitsays'. Run the following code in the terminal.
    gcc -o iwonderwhatitsays task1_W4.c -lcrypto

//Now run the file
    ./iwonderwhatitsays
    Decrypted Message =  49206C6F766520796F750A //./iwonderwhatitsays returns the decrypted message

//Now time to reverse the text-hex conversion to reveal the plain text message (Refer to the README.md file under TEXT-HEX CONVERSION)
    echo "49206C6F766520796F750A" | xxd -p -r
    I love you //YAY! Your partner managed to reveal the secret message. Happy days
