#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<unistd.h>
#include "stiva.h"

char caleFisierHTML[100], caleFisierCSS[100], titlu[50], input[500], text[500], continut[2000], zona2[1000], theme[20] = "LIGHT";
FILE *f,*g;
STIVA st, history, files;

void personalizare_consola(){
    SetConsoleTitle("Creator de Pagini Web");
}

void creareFolder(){

    mkdir(titlu);
}

void creareHTML(){
    strcpy(caleFisierHTML,titlu);                            //Initializare cale fisier cu numele folderului
    strcat(caleFisierHTML, "\\index.html");
    f = fopen(caleFisierHTML,"w");                            //Creare si deschidere fisier
    if(f==NULL)
        printf("Eroare la creare fisier html");               //Verificare daca s-a putut crea si deschide fisierul
    fprintf(f, "%s", " <!DOCTYPE html>\n<html>\n");
    fprintf(f, "%s", toString(st, continut));
    fprintf(f, "%s", "\n\t</div>\n\t<footer><strong>&copy; Copyright 2020, Lupastean Daniel</strong></footer>\n\t</body>\n</html>");
    fclose(f);
}

void creareCSS(){
    strcpy(caleFisierCSS, titlu);
    strcat(caleFisierCSS, "\\style.css");
    g = fopen(caleFisierCSS, "w");
    if(f==NULL)
        printf("Eroare la creare fisier html");
    fprintf(g, "%s", "\n* {\n\tmargin: 0;\n\tpadding: 0;\n}");   // resetare CSS
    fprintf(g, "%s", "\nhtml{\n\theight: 100%;\n}");
    if(strcmp(theme, "LIGHT") == 0)
    {
        fprintf(g, "%s", "\nbody{\n\tcolor: black;\n\tbackground-color : #C0C0C0;\n\ttext-align: center;\n\tmin-height: 100%;\n\tdisplay: flex;\n\tflex-direction: column;\n}");       // setare tema light
        fprintf(g, "%s", "\np{\n\tcolor: #101010;\n\tpadding: 5px;\n}");
        fprintf(g, "%s", "\n#content{\n\tdisplay: block;\n\twidth: 80%;\n\tmargin-left: auto;\n\tmargin-right: auto;\n\tbackground-color : #FFFFFF;\n\tpadding: 20px;\n}");
        fprintf(g, "%s", "\nheader{\n\tpadding:20px;\n\tcolor: black;\n\tfont-size: 40px;\n\tdisplay: block;\n\twidth: 80%;\n\tmargin-left: auto;\n\tmargin-right: auto;\n}");
        fprintf(g, "%s", "\nfooter{\n\tmargin-top:auto;\n\tpadding:10px;\n\tcolor: black;\n}");                           // centrare continut
    }
    else if(strcmp(theme, "DARK") == 0)
    {
        fprintf(g, "%s", "\nbody{\n\tcolor: white;\n\tbackground-color : #C0C0C0;\n\ttext-align: center;\n\tmin-height: 100%;\n\tdisplay: flex;\n\tflex-direction: column;\n}");       // setare tema dark
        fprintf(g, "%s", "\np{\n\tcolor: silver;\n\tpadding: 5px;\n}");
        fprintf(g, "%s", "\n#content{\n\tdisplay: block;\n\twidth: 80%;\n\tmargin-left: auto;\n\tmargin-right: auto;\n\tbackground-color : #101010;\n\tpadding: 20px;\n}");
        fprintf(g, "%s", "\nheader{\n\tpadding:20px;\n\tcolor: black;\n\tfont-size: 40px;\n\tdisplay: block;\n\twidth: 80%;\n\tmargin-left: auto;\n\tmargin-right: auto;\n}");
        fprintf(g, "%s", "\nfooter{\n\tmargin-top:auto;\n\tpadding:10px;\n\tcolor: black;\n}");                           // centrare continut
    }

    else if(strcmp(theme, "RED") == 0)
    {
        fprintf(g, "%s", "\nbody{\n\tcolor: #6a040f;\n\tbackground-color : #6a040f;\n\ttext-align: center;\n\tmin-height: 100%;\n\tdisplay: flex;\n\tflex-direction: column;\n}");       // setare tema dark
        fprintf(g, "%s", "\np{\n\tcolor: #001427;\n\tpadding: 5px;\n}");
        fprintf(g, "%s", "\n#content{\n\tdisplay: block;\n\twidth: 80%;\n\tmargin-left: auto;\n\tmargin-right: auto;\n\tbackground-color : white;\n\tpadding: 20px;\n}");
        fprintf(g, "%s", "\nheader{\n\tpadding:20px;\n\tcolor: #f8edeb;\n\tfont-size: 40px;\n\tdisplay: block;\n\twidth: 80%;\n\tmargin-left: auto;\n\tmargin-right: auto;\n}");
        fprintf(g, "%s", "\nfooter{\n\tmargin-top:auto;\n\tpadding:10px;\n\tcolor: #ffb5a7;\n}");                        // centrare continut
    }


    fprintf(g, "%s", "\nimg{\n\tdisplay: block;\n\tmax-width: 100%;\n\theight: auto;\n\tmargin-left: auto;\n\tmargin-right: auto;\n\tpadding-top: 20px;\n\tpadding-bottom: 20px;\n}");                     // incadrare imagini
    fclose(g);
}

void creareFisiere(){
    fflush(stdin);
    creareHTML();
    creareCSS();
}

void f_save(){
    creareFisiere();
}

void f_title(){                                         /*functie titlu*/
    fflush(stdin);
    titlu[0]=0;
    input[0]=0;
    printf("Titlul Paginii: ");
    scanf("%[^\n]s",input);
    if(input[0] != 0)
    {
        strcpy(titlu, input);
        strcpy(text, "\t<head>\n\t<title>");
        strcat(text, titlu);
        strcat(text, "</title>\n\t <link rel=\"stylesheet\" href=\"style.css\">\n\t</head>\n\t<body>\n\t<header><strong>");
        strcat(text, strupr(titlu));
        strcat(text, "</strong></header>\n\t<div id=\"content\">");
        st = push(st, text);
        history = push(history, " - TITLE");
        creareFolder();
        f_save();
    }
    else
    {
        printf("Titlu invalid.\n");
        Sleep(500);
    }
}

void f_subtitle(){
    fflush(stdin);
    strcpy(text, "\n\t<h2>");
    printf("Introduceti subtitlul: ");
    scanf("%[^\n]s",input);
    strcat(text, input);
    strcat(text, "</h2>");
    st = push(st, text);
    history = push(history, " - SUBTITLE");
    f_save();
}

void f_paragraph(){
    fflush(stdin);
    strcpy(text, "\n\t<p>");
    printf("Introduceti paragraful:  ");
    scanf("%[^\n]s",input);
    strcat(text, input);
    strcat(text, "</p>");
    st = push(st, text);
    history = push(history, " - PARAGRAPH");
    f_save();
}

void f_line(){
    strcpy(text, "\n\t<hr>");
    st = push(st, text);
    history = push(history, " - LINE");
    f_save();
}

void f_space(){
    strcpy(text, "\n\t<br>");
    st = push(st, text);
    history = push(history, " - SPACE");
    f_save();
}

void f_image(){
    char command[100];
    fflush(stdin);
    printf("Introduceti numele imaginii (cu extensie)(1.jpg / 2.jpg):  ");
    scanf("%[^\n]s",input);
    if(fopen(input, "r")==NULL)
    {
        printf("Nume invalid!\n");
        Sleep(1000);
    }
    else{
        strcpy(command, "\"copy \""); //crearea comenzii pentru copierea imaginii in folderul pagini web
        strcat(command, input);
        strcat(command, "\" \"");
        strcat(command,titlu);
        strcat(command, "/");
        strcat(command, input);
        strcat(command, "\"\"");

        files = push(files, input); // adauga numele imaginii in stiva cu nume de fisiere

        strcpy(text, "\n\t<img src = \"");
        strcat(text, input);
        fflush(stdin);
        printf("Dimensiunea imaginii afisate (MICA/MEDIE/MARE) : "); scanf("%s", input);
        if(strcmp(strupr(input), "MICA")==0)
            strcat(text, "\" style=\"width:33%;\">");
        else if(strcmp(strupr(input), "MEDIE")==0)
            strcat(text, "\" style=\"width:66%;\">");
        else if(strcmp(strupr(input), "MARE")==0)
            strcat(text, "\" style=\"width:100%;\">");

        system(command);

        st = push(st, text);
        history = push(history, " - IMAGE");

        Sleep(300);
    }
    f_save();
}

void f_link(){
    char command[100];
    fflush(stdin);
    strcpy(text, "\n\t<a href = \"");
    printf("Introduceti adresa url/calea: ");
    scanf("%[^\n]s",input);
    strcat(text, input);
    strcat(text, "\">");
    printf("Pe ce plasati link-ul? (TEXT/IMAGE) : ");
    fflush(stdin);
    scanf("%[^\n]s",input);
    if (strcmp("TEXT",strupr(input))== 0)
    {
        printf("Introduceti textul: ");
        fflush(stdin);
        scanf("%[^\n]s",input);
        strcat(text, input);
        history = push(history, " - LINK(TEXT)");
        strcat(text, "</a>");
        st = push(st, text);
    }
    else{
        printf("Introduceti numele imaginii (cu extensie):  ");
        fflush(stdin);
        scanf("%[^\n]s",input);
        if(fopen(input, "r")==NULL)
        {
            printf("Nume invalid!\n");
            Sleep(1000);
        }
        else{
            strcpy(command, "\"copy \"");
            strcat(command, input);
            strcat(command, "\" \"");
            strcat(command,titlu);
            strcat(command, "/");
            strcat(command, input);
            strcat(command, "\"\"");

            system(command);

            strcat(text, "<img src = \"");
            strcat(text, input);
            strcat(text, "\">");

            files = push(files, input);
            Sleep(300);
            history = push(history, " - LINK(IMAGE)");
            strcat(text, "</a>");
            st = push(st, text);
        }
    }
    f_save();
}

void f_theme(){
    fflush(stdin);
    printf("Introduceti tema dorita (LIGHT/DARK/RED): ");
    scanf("%s", input);
    if(strcmp(strupr(input),"LIGHT") == 0 || strcmp(strupr(input),"DARK") == 0 || strcmp(strupr(input),"RED") == 0)
        strcpy(theme, input);
    else printf("Tema invalida.");
    f_save();
}

void f_undo(){
    if(!isEmptys(st)){
        char primu[50];
        st = pop(st);
        if(strcmp(primul(history), " - IMAGE")==0 || strcmp(primul(history), " - LINK(IMAGE)")==0)
        {
            strcpy(primu, primul(files));
            files = pop(files);
            if(cauta(files, primu)==NULL)                    //stergere imagine din folder daca imaginea nu mai este folosita nicieri in pagina
            {
                 chdir(titlu);
                 remove(primu);
                 chdir("../");
            }
        }
        if(strcmp(primul(history), " - TITLE")==0)          //stergere toate fisierele si folderele legate de pagina web daca a fost sters titlul
        {
            chdir(titlu);
            remove("index.html");
            remove("style.css");
            chdir("../");
            rmdir(titlu);
            strcpy(titlu, "\0");
        }
        else f_save();
        history = pop(history);
    }

}

void f_view(){
    fflush(stdin);
    char cale[500];
    strcpy(cale, "\"");
    strcat(cale, caleFisierHTML);
    strcat(cale, "\"");
    system(cale);
}

void f_delete(){
    while(!isEmptys(st))
    {
        f_undo();
    }
}

void f_exit(){
    destroys(st);
    destroys(history);
    destroys(files);
    exit(0);
}

void f_leave(){
    f_delete();
    f_exit();
}

void f_info(){
    printf("\n Informatii despre autorul acestei aplicatii:\n");
    printf(" Nume: Lupastean Daniel\n");
    printf(" Grupa: 3111A\n");
    printf(" Specializarea: Calculatoare\n");
    printf(" Anul: 1\n");
    Sleep(4000);
}

int main(){

    personalizare_consola();
    char instructiune[20];
    st = news();                    //stiva cu continutul paginii
    history = news();               //stiva cu istoricul elementelor adaugate pana in prezent
    files = news();                 //stiva cu numele fisierelor din folderul paginii web

    while(1){

        puts(" ----------------- CREATOR PAGINI WEB ---------------------");
        puts("");
        puts(" Lista instructiuni: ");
        puts("");
        puts(" SUBTITLE - adauga subtitlu");
        puts(" PARAGRAPH - adauga un nou paragraf");
        puts(" IMAGE - adauga o noua imagine (din folderul cu programul)");
        puts(" LINK - adauga un link catre o alta pagina web");
        puts(" LINE - adauga o linie orizontala in pagina");
        puts(" SPACE - adauga un rand gol in pagina ");
        puts(" THEME - selectare tema pagina web");
        puts(" UNDO - anuleaza ultima instructiune");
        puts(" DELETE - sterge pagina web curenta");
        puts(" VIEW - deschide in browser pagina creata");
        puts(" INFO - afiseaza in consola informatii despre autorul aplicatiei");
        puts(" LEAVE - inchide aplicatia fara a salva pagina");
        puts(" EXIT - inchide aplicatia salvand pagina creata");
        puts("");
        printf(" Istoric:%s\n", toString(history, zona2 ));
        puts("");

        fflush(stdin);
        if(isEmptys(st)) f_title();                                                         // TITLU
        else
        {
            printf("Instructiune -> "); scanf("%[^\n]s", instructiune);
            if(strcmp("SUBTITLE",strupr(instructiune))==0) f_subtitle();                    // SUBTITLU
            else if(strcmp("PARAGRAPH",strupr(instructiune))==0) f_paragraph();             // PARAGRAF
            else if(strcmp("IMAGE",strupr(instructiune))==0) f_image();                     // IMAGINE
            else if(strcmp("LINK",strupr(instructiune))==0) f_link();                       // LINK
            else if(strcmp("LINE",strupr(instructiune))==0) f_line();                       // LINIE
            else if(strcmp("SPACE",strupr(instructiune))==0) f_space();                     // SPATIU
            else if(strcmp("THEME",strupr(instructiune))==0) f_theme();                     // TEMA
            else if(strcmp("UNDO",strupr(instructiune))==0) f_undo();                       // UNDO
            else if(strcmp("DELETE",strupr(instructiune))==0) f_delete();                   // STERGE
            else if(strcmp("VIEW",strupr(instructiune))==0) f_view();                       // VIZUALIZARE
            else if(strcmp("INFO",strupr(instructiune))==0) f_info();                       // INFORMATII DESPRE AUTOR
            else if(strcmp("LEAVE",strupr(instructiune))==0) f_leave();                     // LEAVE
            else if(strcmp("EXIT",strupr(instructiune))==0) f_exit();                       // LEAVE
            else {printf("Instructiune invalida!");Sleep(400);}                             // MESAJ EROARE
        }
        system("cls");
        strcpy(instructiune, "\0");
    }

}
