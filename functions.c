#include <stdio.h>
#include <math.h>
#include <stdbool.h>

/*
    ESTRUTURA DAS FUNCOES A SEREM UTILIZADAS NO ARQUIVO MAIN
*/

int menu_principal(){
    int opcao_1;
    float num1, num2;
    float soma = 0;

    //INICIO DO LOOP
    do
        {
            system("cls");
            printf("*********************************************\n");
            printf("*********** CALCULADORA FatecCalc ***********\n");
            printf("*********************************************\n");
            printf("*\tMENU PRINCIPAL\t\t\t\t*\n");
            printf("*\t\t\t\t\t\t*\n");
            printf("*\t1. Somatório\t\t\t\t*\n");
            printf("*\t\t\t\t\t\t*\n");
            printf("*\t2. Lógica proposicional \t\t*\n");
            printf("*\t\t\t\t\t\t*\n");
            printf("*\t3. Análise combinatória\t\t\t*\n");
            printf("*\t\t\t\t\t\t*\n");
            printf("*\t4. SAIR\t\t\t\t\t*\n");
            printf("*********************************************\n");
            printf("\n");
            printf("Escolha uma das opcoes: ");
            scanf("%d", &opcao_1);

            //Caso usuario escolha uma opçao invalida

            if ((opcao_1 > 4) || (opcao_1 <= 0)){
                printf("\n\n>ERRO! Digite uma opção válida.\n\n\n\n\n");
                system("pause");
            }

            //opcoes do usuario validas
            switch(opcao_1){
            case 1:
                sub_menu_soma();
                break;
            case 2:
                sub_menu_logica();
                break;
            case 3:
                sub_menu_analise();
                break;
            case 4:
                Sleep(500);
                printf("\n\n\n\n\n\n\nSaindo");
                Sleep(350);
                printf(".");
                Sleep(350);
                printf(".");
                Sleep(350);
                printf(".\n\n\n");
                break;

            }
        }
        while((opcao_1 <= 0) || (opcao_1 > 4));

}

/* -----------------------------------------------------------------------------------------------*/
/*                                                                    Funcao sub menu soma        */

int sub_menu_soma(){
    //declaçao de variaveis
    int opcao_1;
    float num1, num2;
    float soma = 0;

    //inicio do loop
    do
        {
            system("cls");
            printf("*********************************************\n");
            printf("*********** CALCULADORA FatecCalc ***********\n");
            printf("*********************************************\n");
            printf("*\t SUBMENU SOMATÓRIO   \t\t\t*\n");
            printf("*\t\t\t\t\t\t*\n");
            printf("*\t1. Somatório de j = 0 até n.\t\t*\n");
            printf("*\t\t\t\t\t\t*\n");
            printf("*\t2. Somatório de j = 0 até n para\t**\t   a regra (-j)^(j+1).\t\t\t*\n");
            printf("*\t\t\t\t\t\t*\n");
            printf("*\t3. Aproximação do numero pi com \t**\t   somatório até n.\t\t\t*\n");
            printf("*\t\t\t\t\t\t*\n");
            printf("*\t4. Aproximação do neperiano por \t**\t   somatório até n.\t\t\t*\n");
            printf("*\t\t\t\t\t\t*\n");
            printf("*\t5. VOLTAR MENU PRINCIPAL\t\t*\n");
            printf("*\t\t\t\t\t\t*\n");
            printf("*********************************************\n");
            printf("\n");
            printf("Escolha uma das opcoes: ");
            scanf("%d", &opcao_1);

            //Caso usuario escolha uma opçao invalida
            if ((opcao_1 > 5) || (opcao_1 <= 0)){
                printf("\n\nERRO! Digite uma opção válida.\n\n\n\n\n");
                system("pause");
            }

            //opcoes do usuario validas
            switch(opcao_1){
                case 1:
                    somatorio_1();
                    break;
                case 2:
                    somatorio_2();
                    break;
                case 3:
                    somatorio_3();
                    break;
                case 4:
                    somatorio_4();
                    break;
                case 5:
                    menu_principal();
                    break;
            }
        }
        while((opcao_1 <= 0) || (opcao_1 > 5));
}

// "__________________________________________________________________________________________
//                                                          Funcoes de calculos do somatorio

int somatorio_1(){
    char enter_soma[1];
    double soma;
    int num1, i;
    printf("Digite um valor para n: ");     //entrando com valor para n
    scanf("%d", &num1);

    for(i=0;i<=num1;i++){
        soma = soma + i;
    }
    if(num1 <0){
        soma = soma * (-1);
    }
    printf("\n");
    printf("\nO somatório é %.2f", soma);
    printf("\n\n\n");
    system("pause");
    if (enter_soma != ""){
        sub_menu_soma();
    }
}

int somatorio_2(){
    char enter_soma[1];
    float n, j, soma, resp;

    printf("Digite um valor para n: ");
    scanf("%f", &n);
    do{
        //tratamento de erro se negativo
        if(n<0){
            printf("\n\nERRO! Digite valores maiores que 0.\n\n\n\n\n");
            system("pause");
            system("cls");
            sub_menu_soma();
            printf("Digite um valor para n: ");
            scanf("%f", &n);
        }
    }
    while(n<0);

    //>>>> (-J)^(J+1)
    for(j=0;j<=n;j++){
        soma = pow(-j,j+1);
        resp = soma + resp;
    }
    printf("\n");
    printf("\nO somatório é %.2f", resp);
    printf("\n\n\n");
    system("pause");
    if (enter_soma != ""){
        sub_menu_soma();
    }
}

int somatorio_3(){
    char enter_soma[1];
    float soma, resp;
    int n;
    printf("Digite um valor para n (até 178): ");
    scanf("%d", &n);
    do{
        //tratamento de erro se negativo
        if(n<0 || n>178){
            printf("\n\nERRO! Digite valores entre 0  e 178.\n\n\n\n\n");
            system("pause");
            system("cls");
            sub_menu_soma();
            printf("Digite um valor para n: ");
            scanf("%d", &n);
        }
    }
    while(n<0);

    //FORMULA 8 / (4j + 1) * (4j + 3)

    int cont, i, contD;
    int denominador;
    int vetor[n], vetorU[n];
    int vetorMMC[n][2];

    for (i=0;i<=n;i++){
      denominador = (4*i + 1)*(4*i + 3);
      vetor[i] = denominador;
      vetorU[i] = denominador;
      //printf("Esse é o vetorU: %d \n", vetor[i]);
      vetorMMC[i][0] = denominador;
      soma = 8 / denominador;
      resp = soma + resp;
      cont++;
      //printf("denominador: %d\n", denominador);
    }
    printf("\n");

    int j, k, l, p, h, r, u;
    int divisor, d;
    int divisores[999];
    int linha;
    int certo;
    bool mmc = false;
    bool dividiu = false;
    divisor = 3;
    linha = 0;
    double somaMMC=1;
    double divDeno, multNum, somaTodos=0.0;
    long primo;
    double tot;
    double n1;
    n1 = 8.0/3.0;
    int ww=0;
    vetor[0] = 3;
    for(ww=0;ww<=n;ww++){
        //printf("vetorU = %d\n", vetor[ww]);
    }

    if(n>0){
        do{
            for (h = 2; h <= divisor/2 ; h++) {
                if(divisor % h == 0){
                   primo++;
                   break;
                }
             }
             if (primo == 1){
                divisor = divisor;
                for(j=0;j<=n;j++){ //colunas
                    for(k=0;k<1;k++){ //linhas
                        if((vetorMMC[j][0] % divisor == 0) && (vetorMMC[j][0] > 1)){
                            // nao apagar printf("O %d foi dividido por %d sobrou %d \n", vetorMMC[j][1], divisor, vetorMMC[j][0] / divisor);
                            vetorMMC[j][1] = vetorMMC[j][0] / divisor;
                            dividiu = true;
                        }else{
                            vetorMMC[j][1] = vetorMMC[j][0];
                            //printf("entrei no else: %d  << %d --> %d \n", vetorMMC[j][1], vetorMMC[j][0], divisor);
                        }
                    }
                }
                for(p=0;p<=n;p++){
                    //printf("%d /", vetorMMC[p][1]);       //printa a tabela de mmc
                }
                //printf("\n");
                if(dividiu == true){
                    divisores[d] = divisor;
                    somaMMC = somaMMC * divisor;
                    d++;
                    divisor--;
                }
                dividiu = false;
                for(l=0;l<=n;l++){
                    if(vetorMMC[l][1] == 1){
                        certo++;
                    }
                }
                for(p=0;p<=n;p++){
                    vetorMMC[p][0] = vetorMMC[p][1];
                }
                if(certo == n+1){
                    mmc = true;
                }else{
                    mmc = false;
                }

                linha++;
                divisor++;
                certo = 0;
            }else{
                divisor++;
                primo = 1;
            }

        }while(mmc == false);

        u =0;
        for(u=0;u<=n;u++){
            somaTodos = somaTodos + (somaMMC / vetor[u] * 8);
            tot = (somaMMC / vetor[u] * 8);
            //printf("somaMMC = %f e vetorU = %d\n", somaMMC, vetor[u]);
            //printf("valor a somar %.0f \n", tot);
        }

        //printf(">>> \nO denominador é %.0f = \n", somaTodos);
        //printf(">>> \nO mmc é %.0f\n", somaMMC);

        // nao apagar printf("%.0f \n", somaTodos);
        //printf("---------------------------------------------\n");
        // nao apagar printf("%.0f\n", somaMMC);
        printf("\nAproximação de Pi = %.18f\n", somaTodos/somaMMC);

    }else{
        printf("O valor é: N=0 %f \n", n1);
    }

    printf("\n\n\n");
    system("pause");
    if (enter_soma != ""){
        sub_menu_soma();
    }
}



int somatorio_4(){
    char enter_soma[1];
    float soma, resp;
    int n;
    printf("Digite um valor para n (até 11): ");
    scanf("%d", &n);
    do{
        //tratamento de erro se negativo
        if(n<0 || n>11){
            printf("\n\nERRO! Digite valores entre 0 e 11.\n\n\n\n\n");
            system("pause");
            system("cls");
            sub_menu_soma();
            printf("Digite um valor para n: ");
            scanf("%d", &n);
        }
    }
    while(n<0);

    int cont, i, contD;
    int denominador;
    int vetor[n];
    int vetorMMC[n][2];

    double v;
    int a;
    double fatorial, contFat;
    double somaFatorial = 1.0;
    int vetorFat[n];
    double vetorFatD[n];

    //Formula 1/n!

    for(i=0;i<=n;i++){
        for(v=1;v<=i;v++){
            somaFatorial = somaFatorial * v;
            //printf("fatorial de %d: %f\n", i, somaFatorial);
        }
        vetorFat[i] = somaFatorial;
        vetorFatD[i] = somaFatorial;
        vetorMMC[i][0] = somaFatorial;
        //printf("vetorFat de %d: %f\n", i, vetorFatD[i]);
        //printf("vetorMMC de %d: %d\n", i, vetorMMC[i][0]);
        contFat++;
        somaFatorial = 1.0;
    }

    for(a=0;a<=n;a++){
        //printf("VetorMMC: %d\n", vetorMMC[a][0]);
    }

    //////////////////////////////////////////////
    int l, p, r, u, k;
    int j, h;
    int divisor, d;
    int divisores[999];
    int linha;
    int certo;
    bool mmc = false;
    bool dividiu = false;
    divisor = 2;
    linha = 0;
    double somaMMC=1;
    double divDeno, multNum, somaTodos=0;
    int primo;
    double tot;
    vetorFat[0] = 1.0;

    if(n>0){
        do{
            if(divisor > 2){
                for (h = 2; h <= divisor/2 ; h++) {
                    if(divisor % h == 0){
                        //printf("dividiu.. \n");
                       primo++;
                       break;
                    }
                }
            }

             if(divisor == 2){
                primo = 1;
             }
             if (primo == 1){
                divisor = divisor;
                for(j=0;j<=n;j++){ //colunas
                    for(k=0;k<1;k++){ //linhas
                        if((vetorMMC[j][0] % divisor == 0) && (vetorMMC[j][0] > 1)){
                            //printf("O %d foi dividido por %d sobrou %d \n", vetorMMC[j][0], divisor, vetorMMC[j][0] / divisor);
                            vetorMMC[j][1] = vetorMMC[j][0] / divisor;
                            dividiu = true;

                        }else{
                            vetorMMC[j][1] = vetorMMC[j][0];
                            //printf("entrei no else: %d  << %d --> %d \n", vetorMMC[j][1], vetorMMC[j][0], divisor);
                        }
                    }
                }
                for(p=0;p<=n;p++){
                    //printf("%d \n", vetorMMC[p][1]);
                }
                //printf("\n");
                if(dividiu == true){
                    divisores[d] = divisor;
                    somaMMC = somaMMC * divisor;
                    d++;
                    divisor--;
                }
                dividiu = false;
                //printf("\n");

                for(l=0;l<=n;l++){
                    if(vetorMMC[l][1] == 1){
                        //printf("1 certo.. \n");
                        certo++;
                    }
                }
                vetorMMC[0][1] = 1;
                for(p=0;p<=n;p++){
                    vetorMMC[p][0] = vetorMMC[p][1];
                    //printf("%d /", vetorMMC[p][1]);
                }
                //printf("\n");



                if(certo == n+1){
                    //printf("Acabou... \n");
                    mmc = true;
                }else{
                    mmc = false;
                }
                linha++;
                divisor++;
                certo = 0;
            }else{
                divisor++;
                primo = 1;
            }

        }while(mmc == false);


            for(u=0;u<n;u++){
                //printf("somaMMC = %d / vet", somaMMC);
                somaTodos = somaTodos + (somaMMC / vetorFatD[u]);
                tot = (somaMMC / vetorFatD[u]);
                //printf("valor a somar %.0f vetFat %d\n", tot, vetorFatD[u]);
            }
            somaTodos++;
            // nao apagar printf("\nO denominador é %.0f", somaTodos);
            // nao apagar printf("\nO mmc é %.0f\n", somaMMC);

            printf("\n\nAproximação Neperiano = %.18f\n", somaTodos/somaMMC);

    }else{
        printf("O valor é: N=1 é 1 \n");
    }



    printf("\n\n\n");
    system("pause");
    if (enter_soma != ""){
        sub_menu_soma();
    }
}



/* -----------------------------------------------------------------------------------------------*/
/*                                                                  Funcao sub menu logica        */

int sub_menu_logica(){
    //declaçao de variaveis
    int opcao_1;
    float num1, num2;
    float soma = 0;

    //inicio do loop
    do
        {
            system("cls");
            printf("*********************************************\n");
            printf("*********** CALCULADORA FatecCalc ***********\n");
            printf("*********************************************\n");
            printf("*\t SUBMENU LÓGICA PROPOSICIONAL\t\t*\n");
            printf("*\t\t\t\t\t\t*\n");
            printf("*\t1. Lógica ~p\t\t\t\t*\n");
            printf("*\t\t\t\t\t\t*\n");
            printf("*\t2. Lógica ~q\t\t\t\t*\n");
            printf("*\t\t\t\t\t\t*\n");
            printf("*\t3. Lógica p ^ q\t\t\t\t*\n");
            printf("*\t\t\t\t\t\t*\n");
            printf("*\t4. Lógica p V q\t\t\t\t*\n");
            printf("*\t\t\t\t\t\t*\n");
            printf("*\t5. Lógica p VV q\t\t\t*\n");
            printf("*\t\t\t\t\t\t*\n");
            printf("*\t6. Lógica p -> q\t\t\t*\n");
            printf("*\t\t\t\t\t\t*\n");
            printf("*\t7. Lógica p <-> q\t\t\t*\n");
            printf("*\t\t\t\t\t\t*\n");
            printf("*\t8. VOLTAR MENU PRINCIPAL\t\t*\n");
            printf("*********************************************\n");
            printf("\n");
            printf("Escolha uma das opcoes: ");
            scanf("%d", &opcao_1);

            //Caso usuario escolha uma opçao invalida

            if ((opcao_1 > 8) || (opcao_1 <= 0)){
                printf("\n\nERRO! Digite uma opção válida.\n\n\n\n\n");
                system("pause");
            }

            printf("Dica: para F = 0 e V = 1.\n");

            //opcoes do usuario validas
            switch(opcao_1){
            case 1:
                Logica_Proporcional_1();
                break;
            case 2:
                Logica_Proporcional_2();
                break;
            case 3:
                Logica_Proporcional_3();
                break;
            case 4:
                Logica_Proporcional_4();
                break;
            case 5:
                Logica_Proporcional_5();
                break;
            case 6:
                Logica_Proporcional_6();
                break;
            case 7:
                Logica_Proporcional_7();
                break;
            case 8:
                menu_principal();
                break;
            }
        }
        while((opcao_1 <= 0) || (opcao_1 > 8));
}



int Logica_Proporcional_1()
{
    /*logica ~p*/
    char enter_soma[1];
    int P;

    printf("Digite 0 ou 1 para p: ");
    scanf("%d", &P);

    do{
        //tratamento de erro se diferente de 0 e 1.
        if(P<0 || P>1){
            printf("\n\nERRO! Digite somete 0 ou 1.\n\n\n");
            system("pause");
            system("cls");
            sub_menu_logica();
            printf("Digite 0 ou 1 para p: ");
            scanf("%d", &P);
        }
    }
    while(P<0 || P>1);

    if (P == 0){
        printf("~p = V");
        printf("\n\n\n");
        system("pause");
        if (enter_soma != ""){
            sub_menu_logica();
        }
    }
    else if (P == 1){
        printf("~p = F");
        printf("\n\n\n");
        system("pause");
        if (enter_soma != ""){
            sub_menu_logica();
        }
    }
    else{
        printf("Valor inválido!\n");
        printf("\n\n\n");
        system("pause");
        if (enter_soma != ""){
            sub_menu_logica();
        }
    }
}


int Logica_Proporcional_2(){

    /*logica ~q*/
    char enter_soma[1];
    int Q;

    printf("Digite 0 ou 1 para q: ");
    scanf("%d", &Q);

    do{
        //tratamento de erro se diferente de 0 e 1.
        if(Q<0 || Q>1){
            printf("\n\nERRO! Digite somete 0 ou 1.\n\n\n");
            system("pause");
            system("cls");
            sub_menu_logica();
            printf("digite 0 ou 1 para q: ");
            scanf("%d", &Q);
        }
    }
    while(Q<0 || Q>1);

    if (Q == 0){
        printf("~q = V");
        printf("\n\n\n");
        system("pause");
        if (enter_soma != ""){
            sub_menu_logica();
        }
    }
    else if (Q == 1){
        printf("~q = F");
        printf("\n\n\n");
        system("pause");
        if (enter_soma != ""){
            sub_menu_logica();
        }
    }
    else{
        printf("Valor inválido!\n");
        printf("\n\n\n");
        system("pause");
        if (enter_soma != ""){
            sub_menu_logica();
        }
    }
}


 int Logica_Proporcional_3()
{
    /*logica p ^ q*/
    char enter_soma[1];
    int P,Q;

    printf("Digite 0 ou 1 para p: ");
    scanf("%d", &P);
    printf("Digite 0 ou 1 para q): ");
    scanf("%d", &Q);

    do{
        //tratamento de erro se diferente de 0 e 1.
        if(Q<0 || Q>1 || P<0 || P>1){
            printf("\n\nERRO! Digite somete 0 ou 1.\n\n\n");
            system("pause");
            system("cls");
            sub_menu_logica();
            printf("Digite 0 ou 1 para p: ");
            scanf("%d", &P);
            printf("Digite 0 ou 1 para q): ");
            scanf("%d", &Q);
        }
    }
    while(Q<0 || Q>1 || P<0 || P>1);

    if ((P == 1) && (Q == 1)){
        printf("p ^ q = V");
        printf("\n\n\n");
        system("pause");
        if (enter_soma != ""){
            sub_menu_logica();
        }
    }
    else if ((P == 0) || (Q == 0)){
        printf("p ^ q = F");
        printf("\n\n\n");
        system("pause");
        if (enter_soma != ""){
            sub_menu_logica();
        }
    }
    else{
        printf("Valor inválido!\n");
        printf("\n\n\n");
        system("pause");
        if (enter_soma != ""){
            sub_menu_logica();
        }
    }
}


int Logica_Proporcional_4()
{
    /*logica p V q*/
    char enter_soma[1];
    int P, Q;

    printf("Digite 0 ou 1 para p: ");
    scanf("%d", &P);
    printf("Digite 0 ou 1 para q): ");
    scanf("%d", &Q);

    do{
        //tratamento de erro se diferente de 0 e 1.
        if(Q<0 || Q>1 || P<0 || P>1){
            printf("\n\nERRO! Digite somete 0 ou 1.\n\n\n\n\n");
            system("pause");
            system("cls");
            sub_menu_logica();
            printf("Digite 0 ou 1 para p: ");
            scanf("%d", &P);
            printf("Digite 0 ou 1 para q): ");
            scanf("%d", &Q);
        }
    }
    while(Q<0 || Q>1 || P<0 || P>1);

    if ((P == 0) && (Q == 0)){
        printf("p V q = F");
        printf("\n\n\n");
        system("pause");
        if (enter_soma != ""){
            sub_menu_logica();
        }
    }
    else if ((P == 1) || (Q == 1)){
        printf("p V q = V");
        printf("\n\n\n");
        system("pause");
        if (enter_soma != ""){
            sub_menu_logica();
        }
    }
    else{
        printf("Valor inválido!\n");
        printf("\n\n\n");
        system("pause");
        if (enter_soma != ""){
            sub_menu_logica();
        }
    }
}



int Logica_Proporcional_5()
{
    /*logica p VV q*/
    char enter_soma[1];
    int P, Q;

    printf("Digite 0 ou 1 para p: ");
    scanf("%d", &P);
    printf("Digite 0 ou 1 para q: ");
    scanf("%d", &Q);

    do{
        //tratamento de erro se diferente de 0 e 1.
        if(Q<0 || Q>1 || P<0 || P>1){
            printf("\n\nERRO! Digite somete 0 ou 1.\n\n\n\n\n");
            system("pause");
            system("cls");
            sub_menu_logica();
            printf("Digite 0 ou 1 para p: ");
            scanf("%d", &P);
            printf("Digite 0 ou 1 para q: ");
            scanf("%d", &Q);
        }
    }
    while(Q<0 || Q>1 || P<0 || P>1);

    if (P == Q){
        printf("p VV q = F");
        printf("\n\n\n");
        system("pause");
        if (enter_soma != ""){
            sub_menu_logica();
        }
    }
    else if (P != Q){
        printf("p VV q = V");
        printf("\n\n\n");
        system("pause");
        if (enter_soma != ""){
            sub_menu_logica();
        }
    }
    else{
        printf("Valor inválido!\n");
        printf("\n\n\n");
        system("pause");
        if (enter_soma != ""){
            sub_menu_logica();
        }
    }
}


int Logica_Proporcional_6()
{
    /*logica p -> q*/
    char enter_soma[1];
    int P, Q;

    printf("Digite 0 ou 1 para p: ");
    scanf("%d", &P);
    printf("Digite 0 ou 1 para q: ");
    scanf("%d", &Q);

    do{
        //tratamento de erro se diferente de 0 e 1.
        if(Q<0 || Q>1 || P<0 || P>1){
            printf("\n\nERRO! Digite somete 0 ou 1.\n\n\n\n\n");
            system("pause");
            system("cls");
            sub_menu_logica();
            printf("Digite 0 ou 1 para p: ");
            scanf("%d", &P);
            printf("Digite 0 ou 1 para q: ");
            scanf("%d", &Q);
        }
    }
    while(Q<0 || Q>1 || P<0 || P>1);


    if ((P == 0) && (Q == 1)){
        printf("p -> q = F");
        printf("\n\n\n");
        system("pause");
        if (enter_soma != ""){
            sub_menu_logica();
        }
    }
    else{
        printf("p -> q = V");
        printf("\n\n\n");
        system("pause");
        if (enter_soma != ""){
            sub_menu_logica();
        }
    }

    if(Q<0 || Q>1 || P<0 || P>1) {
        printf("Valor inválido!\n");
        printf("\n\n\n");
        system("pause");
        if (enter_soma != ""){
            sub_menu_logica();
        }
    }
}

int Logica_Proporcional_7()
{
    /*logica p <-> q*/
    char enter_soma[1];
    int P, Q;

    printf("Digite 0 ou 1 para p: ");
    scanf("%d", &P);
    printf("Digite 0 ou 1 para q: ");
    scanf("%d", &Q);

    do{
        //tratamento de erro se diferente de 0 e 1.
        if(Q<0 || Q>1 || P<0 || P>1){
            printf("\n\nERRO! Digite somete 0 ou 1.\n\n\n\n\n");
            system("pause");
            system("cls");
            sub_menu_logica();
            printf("Digite 0 ou 1 para p: ");
            scanf("%d", &P);
            printf("Digite 0 ou 1 para q: ");
            scanf("%d", &Q);
        }
    }
    while(Q<0 || Q>1 || P<0 || P>1);

    if (P == Q){
        printf("p <-> q = V");
        printf("\n\n\n");
        system("pause");
        if (enter_soma != ""){
            sub_menu_logica();
        }
    }
    else if (P != Q){
        printf("p <-> q = F");
        printf("\n\n\n");
        system("pause");
        if (enter_soma != ""){
            sub_menu_logica();
        }
    }
    else{
        printf("Valor inválido!\n");
        printf("\n\n\n");
        system("pause");
        if (enter_soma != ""){
            sub_menu_logica();
        }
    }
}



/* -----------------------------------------------------------------------------------------------*/
/*                                                                 Funcao sub menu analise        */

int sub_menu_analise(){
    //declaçao de variaveis
    int opcao_1;
    float num1, num2;
    float soma = 0;

    //inicio do loop
    do
        {
            system("cls");
            printf("*********************************************\n");
            printf("*********** CALCULADORA FatecCalc ***********\n");
            printf("*********************************************\n");
            printf("*\t SUBMENU ANÁLISE COMBINATÓRIA\t\t*\n");
            printf("*\t\t\t\t\t\t*\n");
            printf("*\t1. Permutacao Simples: P(n).\t\t*\n");
            printf("*\t\t\t\t\t\t*\n");
            printf("*\t2. Aranjo Simples: A(n,k).\t\t*\n");
            printf("*\t\t\t\t\t\t*\n");
            printf("*\t3. Combinacao Simples: C(n,k).\t\t*\n");
            printf("*\t\t\t\t\t\t*\n");
            printf("*\t4. Arranjo c/ Repeticao: AR(n,k).\t*\n");
            printf("*\t\t\t\t\t\t*\n");
            printf("*\t5. Combinacao c/ Repeticao: CR(n,k).*\n");
            printf("*\t\t\t\t\t\t*\n");
            printf("*\t6. Permutacao c/ Repeticao:\t\t**\t   PR(n, k1,...,kp).\t\t\t*\n");
            printf("*\t\t\t\t\t\t*\n");
            printf("*\t7. VOLTAR MENU PRINCIPAL\t\t*\n");
            printf("*\t\t\t\t\t\t*\n");
            printf("*********************************************\n");
            printf("\n");
            printf("Escolha uma das opcoes: ");
            scanf("%d", &opcao_1);

            //Caso usuario escolha uma opçao invalida
            if ((opcao_1 > 7) || (opcao_1 <= 0)){
                printf("\n\n>>> ERRO! Digite uma opção válida.\n\n\n\n\n");
                system("pause");
            }

            //opcoes do usuario validas
            switch(opcao_1){
            case 1:
                analise1();
                break;
            case 2:
                analise2();
                break;
            case 3:
                analise3();
                break;
            case 4:
                analise4();
                break;
            case 5:
                analise5();
                break;
            case 6:
                analise6();
                break;
            case 7:
                menu_principal();
                break;
            }
        }
        while((opcao_1 <= 0) || (opcao_1 > 7));
}

//------------------------ codigo anlise

int analise1()
{
    int enter_soma[1];
    int numm;
    double fatt;

    printf("\nDigite um valor para n: ");
    scanf("%d", &numm);

     do{
        if(numm < 0 || numm > 170) {
            printf("\n\nErro! n tem que ser maior ou igual a 0. \n      E menor ou igual a 170.\n");
            system("pause");
            system ("cls");
            sub_menu_analise();
            printf("\nDigite um valor para n: ");
            scanf("%d", &numm);
        }
    }
    while(numm < 0 || numm > 170);

    for (fatt = 1.0; numm > 1.0; numm = numm - 1.0) {
        fatt = fatt * numm;

    }
    printf("\nPermutação Simples: P(n) = %.0f.", fatt);

    printf("\n\n\n");
    system("pause");
    if (enter_soma != ""){
        sub_menu_analise();
    }

}

int analise2()
{

    int enter_soma[1];
    int K2, N2;
    double kk2, kfat, k2fat, nfat2;
    double arranjo;

    printf("\nDigite um valor para n: ");
    scanf("%d", &N2);
    printf("Digite um valor para k: ");
    scanf("%d", &K2);
    kk2 = N2 - K2;
    printf("soma = %f", kk2);
    do{

        if(K2 > N2 || N2 > 170) {
            printf("\n\nErro! k tem que ser maior que 0. \n      E menor ou igual a 170.\n");
            system("pause");
            system ("cls");
            sub_menu_analise();
            printf("\nDigite um valor para n: ");
            scanf("%d", &N2);
            printf("\nDigite um valor para k: ");
            scanf("%d", &K2);
            kk2 = N2 - (K2);
        }
    }
    while(K2 > N2 || N2 > 170);

    if (N2 >= 0) {
        for (nfat2 = 1.0; N2 > 1.0; N2 = N2 - 1.0) {
            nfat2 = nfat2 * N2;
        }
            //printf("\nnfat2 se n >0 = %f", nfat2);
    }


    else {
        for (nfat2 = 1.0; N2 < 0.0; N2 = N2 + 1.0) {
            nfat2 = nfat2 * N2;
    }
           // printf("\nnfat2 se n<0 = %f", nfat2);
    }

    if (kk2 >= 0) {

        for (k2fat = 1.0; kk2 > 1.0; kk2 = kk2 - 1.0) {
        k2fat = k2fat * kk2;
            }
                //printf("\nk2fat se k>0 = %f", k2fat);
    }

    else {
        for (k2fat = 1.0; kk2 < 0.0; kk2 = kk2 + 1.0)
        {
        k2fat = k2fat * kk2 ;
    }
            // printf("\nkfat2 se k<0 = %f", k2fat);

    }


    arranjo = nfat2 / k2fat;


    printf("\nArranjo simples: A(n,k) = %f.", arranjo);

    printf("\n\n\n");
    system("pause");
    if (enter_soma != ""){
        sub_menu_analise();
    }

}


int analise3()
{
    int enter_soma[1];

    int n3, p3;
    double sub3, conta3, nfat3, pfat3, subfat3;
    double comb;
    printf("\nDigite um valor para n: ");
    scanf("%d", &n3);
    printf("\nDigite um valor para k: ");
    scanf("%d", &p3);
    sub3 = n3 - p3;

    do{

        if(p3 > n3 || n3 >= 90 || n3 < 0) {
            printf("\nErro! k tem que ser menor que n.\n      E n maior que 0 e menor ou igual a 90.\n");
            system("pause");
            system ("cls");
            sub_menu_analise();
            printf("\nDigite um valor para n: ");
            scanf("%f", &n3);
            printf("\nDigite um valor para k: ");
            scanf("%f", &p3);
           sub3 = n3 - p3;
        }
    }
    while(p3 > n3 || n3 >= 90 || n3 < 0);

    for (nfat3 = 1.0; n3 > 1.0; n3 = n3 - 1.0) {
        nfat3 = nfat3 * n3;
    }

    for (pfat3 = 1.0; p3 > 1.0; p3 = p3 - 1.0) {
        pfat3 = pfat3 * p3;
    }

    for (subfat3 = 1.0; sub3 > 1.0; sub3 = sub3 - 1.0) {
        subfat3 = subfat3 * sub3;
    }

    comb = nfat3 /(pfat3 * subfat3);


    printf("\nCombinação Simples: C(n,k) = %f.", comb);


    printf("\n\n\n");
    system("pause");
    if (enter_soma != ""){
        sub_menu_analise();
    }
}

int analise4()
{
    int enter_soma[1];

    double exp4=1;
    int n4, k4, i4, j4, d4, g4;

    printf("\nDigite um valor para n: ");
    scanf("%d", &n4);
    printf("Digite um valor para k: ");
    scanf("%d", &k4);

    i4 = k4;
    d4 = k4;

    j4 = n4;
    g4 = n4;
    if ( n4 > 0 && k4 > 0) {
            while (k4 > 0)
            {
                exp4 = exp4 * n4;
                k4 --;
            }
    }

    else if (n4 < 0 && k4 > 0) {
             j4 = j4 * -1;

            while (i4 > 0)
           {
                exp4 = exp4 * j4;
                i4 --;
           }
            if (k4%2 == 0) {
                exp4 = exp4 * 1;
            }
            else {
                exp4 = exp4 * -1;
            }
    }

    else if (n4 > 0 && k4 < 0){
            i4 = i4 * -1;

            while (i4 > 0)
           {
                exp4 = exp4 * j4;
                i4 --;
           }
           exp4 = 1.0 / exp4;

    }

    else if (n4 < 0 && k4 < 0){
            i4 = i4 * -1;
            j4 = j4 * -1;
            while (i4 > 0)
           {
                exp4 = exp4 * j4;
                i4 --;
           }
           if (k4%2 == 0) {
            exp4 = 1.0 / exp4;
           }
           else if (k4%2 != 0) {
           exp4 = -1.0 / exp4;
           }
    }

        printf("\nArranjo com Repetição: AR(n,k) = %f.", exp4);

        printf("\n\n\n");
        system("pause");
        if (enter_soma != ""){
            sub_menu_analise();
        }
}

int analise5()
{
    int enter_soma[1];

    //float n5, k5, nn5, soma5, k2, i5, a, b, kk5;
    //float divisao5;
    int n5, k5;
    double nn5, soma5, k2, i5, a, b, kk5;
    double divisao5;

    printf("\nDigite um valor para n: ");
    scanf("%d", &n5);
    printf("Digite um valor para k: ");
    scanf("%d", &k5);

    kk5 = k5 - 1.0;
    soma5 = kk5 + n5;
    nn5 = n5 - 1.0;

    do{
        if(k5 < 0.0 || soma5 > 150.0) {
               if(k5 < 0.0 ) {
                    printf("\n\nErro! k tem que ser maior ou igual a 0.");
                    }

                else  {
                    printf("\n\nErro! a soma de n + k deve ser menor que 150.\n");
                    }

                system("pause");
                system ("cls");
                sub_menu_analise();
                printf("\nDigite um valor para n: ");
                scanf("%f", &n5);
                printf("\nDigite um valor para k: ");
                scanf("%f", &k5);
                kk5 = k5 - 1;
                soma5 = kk5 + n5;
                nn5 = n5 - 1;
        }
    }

    while(k5 < 0.0 || soma5 > 150.0);

    for(i5 = 1.0 ; soma5 > 1.0 ; soma5 = soma5 - 1.0)
      {
          i5 = i5 * soma5;
      }

        for( b = 1.0 ; k5 > 1.0; k5 = k5 - 1.0)
        {
          b = b * k5;
      }

        for(a = 1.0; nn5 > 1.0; nn5 = nn5 - 1.0)
      {
          a = a * nn5;
      }

        divisao5 = i5 / (b * a);

        printf("\nCombinção com Repetição: CR(n,k) = %f.", divisao5);

    printf("\n\n\n");
    system("pause");
    if (enter_soma != ""){
        sub_menu_analise();
    }
}


int analise6()
{
    char enter_soma[1];
    int fatorial(int n){
      int i = 1, vAux = 1;
        while(n >= i){
          vAux = vAux * i;
          i++;
        }
      return vAux;
    }

    int n= 0, k[100], repElem= 0, resultado = 0, vAux=1, i, n2;

    printf("\nDigite um valor para n (total elementos): ");
    scanf("%d", &n);

    printf("Digite quantos k (elementos se repetem): ");
    scanf("%d", &repElem);

    for(i=0;i < repElem; i++){
        printf("Digite o valor para o %dº k (elemento): ", i+1);
        scanf("%d", &k[i]);
        if(k[i] == 0){
            break;
        }
        vAux= vAux*fatorial(k[i]);
    }
    n2=fatorial(n);
    resultado=(n2/vAux);
    int o, soma2=0;
    for(o = 0; o<repElem; o++){
        soma2 = soma2 + k[o];
    }

    if( soma2 > n || repElem > n || k[i-1] == 0){
        printf("\nERRO! O k ou a soma dos k não pode \n      ser maior que n\n      e o valor do elemento não pode ser 0.\n\n");
        system("pause");
        system ("cls");
        sub_menu_analise();

    }
    else{
        printf("\nPermutação com Repetição: P(n,k1,..,kp) = %d.\n", resultado);
        system("pause");
        printf("\n\n\n");
        system("pause");
        if (enter_soma != ""){
           sub_menu_analise();
        }
    }

}


