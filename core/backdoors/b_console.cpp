do{
    string bcmd;
    char *str2, *str3;

    rlutil::setColor(9);
    cout << "l0l";
    // Set White Color
    rlutil::setColor(15);
    cout << ":";
    // Set Red Color
    rlutil::setColor(12);
    cout << usetxt;
    rlutil::setColor(9);
    printf(" > ");
    // Set White Color
    rlutil::setColor(15);

    getline( cin, bcmd );
    //char *usecmd = &bcmd[0u];
    //char *usecmd2 = &bcmd[0u];
    char* usecmd = strdup(bcmd.c_str());
    char* usecmd2 = strdup(bcmd.c_str());

    strcpy(usecmd2,usecmd);

    strtok(usecmd2, " ");

    string modulen = str;

    if (strlen(usecmd) == 0 || usecmd[0] == '\r' || usecmd[0] == '\n');

    // Backdoor Commands

    else if(strcmp(usecmd, "back") == 0){
        goto mainConsole;
    }
    else if(strcmp(usecmd, "help") == 0){
        backdoorHelp();
    }
    else if (strcmp(usecmd,"exit") == 0){
        closeApp();
    }
    else if(strcmp(usecmd2,"os") == 0){

        // Set White Color
        rlutil::setColor(15);

        str2 =  shorter(usecmd,3);

        if(usecmd[3] == '\0'){
            osCommand();
        }else{
            printf("\n");
            system(str2);
        }
        printf("\n");

    }
    else if(strcmp(usecmd, "clear") == 0){
        clear();
    }
    else if(strcmp(usecmd, "show options") == 0){

        rlutil::setColor(2);
        cout <<
                "\n\tModule options (" << modulen << "):\n\n"
                "\t\tName\t" << "\tDescription" << "\t\tCurrent Setting\n"
                "\t\t----\t" << "\t-----------" << "\t\t---------------\n"
                "\t\tLHOST\t" << "\tConnection Host\t\t" << lhost << "\n"
                "\t\tLPORT\t" << "\tConnection Port\t\t" << lport << "\n\n";

    }
    else if(strcmp(usecmd2, "set") == 0){

        str2 = shorter(usecmd2,4);

        if( str2[0] == 'L' && str2[1] == 'H' && str2[2] == 'O' && str2[3] == 'S' && str2[4] == 'T' && str2[5] == ' ' ){
            str3 = shorter(str2,6);

            lhost = str3;
            cout << "\nLHOST -> " << str3 << "\n\n";

        }
        else if(str2[0] == 'L' && str2[1] == 'P' && str2[2] == 'O' && str2[3] == 'R' && str2[4] == 'T' && str2[5] == ' '){
            str3 = shorter(str2,6);

            lport = str3;
            cout << "\nLPORT -> " << str3 << "\n\n";
        }
        else{
            rlutil::setColor(12);
            cout << "This option is not available.\n";
        }
    }

    else if(strcmp(usecmd2, "unset") == 0){

        str2 = shorter(usecmd2,6);

        if( str2[0] == 'L' && str2[1] == 'H' && str2[2] == 'O' && str2[3] == 'S' && str2[4] == 'T'){
            lhost = "None";
        }
        else if(str2[0] == 'L' && str2[1] == 'P' && str2[2] == 'O' && str2[3] == 'R' && str2[4] == 'T'){
            lport = "None";
        }
        else{
            rlutil::setColor(12);
            cout << "This option is not available.\n";
        }
    }

    else if(strcmp(usecmd, "generate") == 0){
        if(lhost == "None" || lport == "None"){
            cout << "\nSet options before generate payload.\n\n";
        }
        else{
            if(modulen == "backdoors/unix/python/reverse_tcp")
                unix_python_reverse_tcp(lhost,lport);
            else if(modulen == "backdoors/unix/perl/reverse_tcp")
                unix_perl_reverse_tcp(lhost,lport);
            else if(modulen == "backdoors/unix/bash/reverse_tcp")
                unix_bash_reverse_tcp(lhost,lport);
            else if(modulen == "backdoors/unix/ruby/reverse_tcp")
                unix_ruby_reverse_tcp(lhost,lport);
            else if(modulen == "backdoors/windows/asm/reverse_tcp")
                windows_asm_reverse_tcp(lhost,lport);
            else if(modulen == "backdoors/windows/ps/reverse_tcp")
                windows_ps_reverse_tcp(lhost,lport);
        }
    }

    else{
        // Set Red Color
        rlutil::setColor(12);
        printf("[-] Unknown command: %s\n", usecmd);
    }

}while(1);
