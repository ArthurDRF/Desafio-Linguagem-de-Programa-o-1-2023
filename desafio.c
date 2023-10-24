#include <stdio.h>
#include <locale.h>
//To utilizando GITHUB
// Definindo os 3 Vetores Globais, e uma para a busca dos médicos.
char medico[20];
char medico1[20];
char medico2[20];
char buscador[20];

//Definindo os 3 Vetores Globais para as datas de consulta, e uma para a sua busca.
char data_consulta[11];
char data_consulta1[11];
char data_consulta2[11];
char buscadorConsulta[11];


//Função que abre o arquivo gerado e le seus dados.
abrirArquivo(){

    //Abre o arquivo, dados.txt para leitura(r = read)
    FILE *arquivo;
    arquivo = fopen("dados.txt", "r");

//Passa os nomes dos médicos para os vetores do programa.
    fread(medico, sizeof(medico), 1 , arquivo);
    fread(medico1, sizeof(medico1), 1 , arquivo);
    fread(medico2, sizeof(medico2), 1, arquivo);

//Passa as datas das consultas para os vetores do programa.
    fread(data_consulta, sizeof(data_consulta), 1 , arquivo);
    fread(data_consulta1, sizeof(data_consulta1), 1 , arquivo);
    fread(data_consulta2, sizeof(data_consulta2), 1 , arquivo);

    fclose(arquivo);
}

//Função que compara as strings de médicos para a busca.
int compararMedicos(){
         int i = 0;
         /* A Função vai comparar caractere por caractere do que o usuario procura (buscador), com os médicos
         nos vetores se o primeiro médico for igual, ela retorna com o valor 1, caso seja o segundo 2 e terceiro 3*/
    while(buscador[i] == medico[i]){
     i++;
     if(i == 20 && buscador[i] == medico[i]){
          return 1;
        }
    }
    while(buscador[i] == medico1[i]){
     i++;
        if(i == 20 && buscador[i] == medico1[i]){
            return 2;
        }
    }
    while(buscador[i] == medico2[i]){
        i++;
        if(i == 20 && buscador[i] == medico2[i]){
            return 3;
        }
    }
}

//Função que compara as strings de consulta para busca.
int compararConsultas(){
         int i = 0;
         /* A Função vai comparar caractere por caractere do que o usuario procura (buscadorConsulta), com as consultas
         nos vetores se a consulta 1 for igual, ela retorna com o valor 1, caso seja a segunda 2 e terceira 3*/
    while(buscadorConsulta[i] == data_consulta[i]){
        i++;
        if(i == 11 && buscadorConsulta[i] == data_consulta[i]){
            return 1;
        }
    }while(buscadorConsulta[i] == data_consulta1[i]){
        i++;
     if(i == 11 && buscadorConsulta[i] == data_consulta1[i]){
            return 2;
        }
    }while(buscadorConsulta[i] == data_consulta2[i]){
        i++;
        if(i == 11 && buscadorConsulta[i] == data_consulta2[i]){
            return 3;
        }
    }
}

//Função que salva os valores para lançar no arquivo posteriormente.
create(){

    printf("Digite o nome do médico: \n");
        scanf("%s",&medico[0]);
    printf("Digite o nome do segundo médico: \n");
        scanf("%s",&medico1[0]);
    printf("Digite o nome do terceiro médico: \n");
        scanf("%s",&medico2[0]);
    printf("Digite a data da primeira consulta: \n");
        scanf("%s",&data_consulta[0]);
    printf("Digite a data da segunda consulta: \n");
        scanf("%s",&data_consulta1[0]);
    printf("Digite a data da terceira consulta: \n");
        scanf("%s",&data_consulta2[0]);

}

//Função que lista todos os dados contidos no arquivo
Listadados(){
    //A Função primeiramente abre o arquivo, e passa as informações contidas nele para os vetores do programa.
    abrirArquivo();
    //Assim que os vetores passam a ter os valores do arquivo, a função imprime os valores dos vetores.
    printf("\nMédico 1: %s\n", medico);
    printf("Médico 2: %s\n", medico1);
    printf("Médico 3: %s\n", medico2);
    printf("Data de Consulta 1: %s\n", data_consulta);
    printf("Data de Consulta 2: %s\n", data_consulta1);
    printf("Data de Consulta 3: %s\n\n", data_consulta2);

}

//Função que busca o médico e sua respectiva consulta pelo nome do médico
pesquisaMedico(){
    //A Função primeiramente abre o arquivo, e passa as informações contidas nele para os vetores do programa.
    abrirArquivo();
    //Aqui lê-se o buscador, que é o nome que o úsuario procura, utilizado na função compararMedicos().
    printf("Digite o nome do médico a ser encontrado\n");
    scanf("%s", &buscador[0]);

    int compara = compararMedicos(); // Passamos o valor retornado pela função comparar médicos(1,2 ou 3) para está variavel.
    printf("%i",compara);
    //Então verificamos qual médico é igual ao procurado pelo usuario, e imprimimos seu nome e sua respectiva consulta salva.
    if(compara == 1){
        printf("\nMédico: %s\n", medico);
        printf("Data de Consulta: %s\n", data_consulta);
    }else if(compara == 2){
        printf("Médico 2: %s\n", medico1);
        printf("Data de Consulta: %s\n", data_consulta1);
    }else if(compara == 3){
        printf("Médico: %s\n", medico2);
        printf("Data de Consulta: %s\n", data_consulta2);
    }else{
        printf("Médico não encontrado\n");
    }
}

pesquisaConsulta(){
//4 – Pesquisa pela data de consulta e mostra todos na tela.
    abrirArquivo();

    printf("Digite a data da consulta\n");
    scanf("%s", &buscadorConsulta[0]);

    int compara = compararConsultas();

    if(compara == 1){
        printf("\nMédico: %s\n", medico);
        printf("Data de Consulta: %s\n", data_consulta);
    }else if(compara == 2){
        printf("Médico 2: %s\n", medico1);
        printf("Data de Consulta: %s\n", data_consulta1);
    }else if(compara == 3){
        printf("Médico: %s\n", medico2);
        printf("Data de Consulta: %s\n", data_consulta2);
    }else{
        printf("Médico não encontrado\n");
    }
}

update(){
//5 – Altera dados. Pesquisa pelo nome completo do médico.
    // Perguntar se é isso!

    abrirArquivo();

    printf("Digite o nome do médico a ser encontrado \n");
    scanf("%s", &buscador[0]);

    int compara = compararMedicos();

    if(compara == 1){
        printf("Digite o nome do médico atualizado: \n");
        scanf("%s", &medico[0]);
        printf("Digite a data de consulta atualizada: \n");
        scanf("%s", &data_consulta[0]);
        printf("\nDados atualizados com sucesso! (Feche o programa para as alterações serem salvas no arquivo)\n\n");
    }else if(compara == 2){
        printf("Digite o nome do médico atualizado: \n");
        scanf("%s", &medico1[0]);
        printf("Digite a data de consulta atualizada: \n");
        scanf("%s", &data_consulta1[0]);
        printf("\nDados atualizados com sucesso! (Feche o programa para as alterações serem salvas no arquivo)\n\n");
    }else if(compara == 3){
        printf("Digite o nome do médico atualizado: \n");
        scanf("%s", &medico2[0]);
        printf("Digite a data de consulta atualizada: \n");
        scanf("%s", &data_consulta2[0]);
        printf("\nDados atualizados com sucesso! (Feche o programa para as alterações serem salvas no arquivo)\n\n");
    }else{
        printf("Médico não encontrado\n\n");
    }
}
exclude(){
//6 – Exclui dados. Pesquisa pelo nome completo do médico.


    abrirArquivo();

    printf("Digite o nome do médico a ser encontrado \n");
    scanf("%s", &buscador[0]);

    int compara = compararMedicos();

    if(compara == 1){
        medico[0] = '\0';
        data_consulta[0] = '\0';
        printf("\nMédico excluido com sucesso! (Feche o programa para as alterações serem salvas no arquivo)\n\n");
    }else if(compara == 2){
        medico1[0] = '\0';
        data_consulta1[0] = '\0';
        printf("\nMédico excluido com sucesso! (Feche o programa para as alterações serem salvas no arquivo)\n\n");
    }else if(compara == 3){
        medico2[0] = '\0';
        data_consulta2[0] = '\0';
        printf("\nMédico excluido com sucesso! (Feche o programa para as alterações serem salvas no arquivo)\n\n");
    }else{
        printf("Médico não encontrado\n\n");
    }
}

close(){

   FILE *arquivo;
   arquivo = fopen("dados.txt","w");

   fwrite(medico , 1 , sizeof(medico) , arquivo);
   fwrite(medico1 , 1 , sizeof(medico1) , arquivo);
   fwrite(medico2 , 1 , sizeof(medico2) , arquivo);
   fwrite(data_consulta , 1 , sizeof(data_consulta) , arquivo);
   fwrite(data_consulta1 , 1 , sizeof(data_consulta1) , arquivo);
   fwrite(data_consulta2 , 1 , sizeof(data_consulta2) , arquivo);

   fclose(arquivo);

    exit(0);
}

int main(){

    setlocale(LC_ALL,"Portuguese");

    int escolha;

    while(1){

        printf("Bem-Vindo ao Programa desafio:\n \n  Para selecionar a opção basta digitar o número:\n1- Cadastrar os dados\n2- Listar todos os médicos existentes\n3- Pesquisar dados pelo nome do médico\n4- Pesquisar data de consultas\n5- Alterar dados\n6- Excluir dados\n0- Para fechar o programa\n");
        scanf("%i",&escolha);
        switch (escolha){

            case 0 : //Funciona
            close();
            break;

            case 1 : //funciona
            create();
            break;

            case 2: //funciona
            Listadados();
            break;

            case 3: //Funciona
            pesquisaMedico();
            break;

            case 4: //Funciona
            pesquisaConsulta();
            break;

            case 5: //Funciona
            update();
            break;

            case 6: //Funciona
            exclude();
            break;

            default: // Funciona
            printf("Código Invalido\n");
            break;

        }
    }
}
