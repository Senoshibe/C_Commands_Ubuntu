# C_Commands_Ubuntu
// COMMON UBUNTU COMMANDS

    // TEXT-HEX CONVERSION

        // Convert plain text value into a hexi-decimal string
        echo "text" | xxd -p

        //Convert hexi-decimal string to plain text
        echo "text" | xxd -p -r
    
    //CREATING RUNABLE FILE 

        //creating runnable file from .cfile
            gcc -o preferredfilename examplefile.c -lcrypto //NOTE: 'preferredfilename' would be the name of the runable file once created from the .c file which in this case is the examplefile.c
        
        //run the file
            ./preferredfilename