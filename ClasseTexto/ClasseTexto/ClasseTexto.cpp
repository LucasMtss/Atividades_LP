// ClasseTexto.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>
#include "Texto.h"
#include <clocale>

int main()
{
    setlocale(LC_ALL, "Portuguese");
    Texto texto;

    texto.adicionar("Teste");
    texto.adicionar("testando");
    texto.adicionar("1");
    texto.adicionar("2");
    texto.adicionar("3");

    cout << "Texto -> " << texto.getTexto() << endl << endl;
    cout <<"Numero de linhas: " << texto.getNumeroLinhas() << endl << endl;
    cout <<"Tamanho: " << texto.tamanho() << endl << endl;
    cout <<"Capacidade: " << texto.capacidade() << endl << endl;
    cout << "Obter linha " << "2 -> " << texto.obterLinha(2) << endl << endl;

    texto.alterar("testando", "testando 123");
    cout <<"Alterar linha ('testando' para 'testando 123') -> " << texto.getTexto() << endl << endl;
    
    texto.alterar("testando 456", 2);
    cout <<"Alterar linha 2 para 'testando 456' -> " << texto.getTexto() << endl << endl;

    cout << "pesquisar por 'testando 123' -> ";
    if(texto.pesquisar("testando 123") != string::npos)
         cout << "ACHOU" << endl << endl;
    else
         cout << "NAO ACHOU" << endl << endl;
    
    cout << "pesquisar por 'testando 456' -> ";
    if(texto.pesquisar("testando 456") != string::npos)
         cout << "ACHOU" << endl << endl;
    else
         cout << "NAO ACHOU" << endl << endl;

    cout << "Excluindo texto" << endl << endl;

    texto.excluir();

    cout << "Texto -> " << texto.getTexto() << endl << endl;
    cout << "Numero de linhas ->  " << texto.getNumeroLinhas() << endl << endl;
}

// Executar programa: Ctrl + F5 ou Menu Depurar > Iniciar Sem Depuração
// Depurar programa: F5 ou menu Depurar > Iniciar Depuração

// Dicas para Começar: 
//   1. Use a janela do Gerenciador de Soluções para adicionar/gerenciar arquivos
//   2. Use a janela do Team Explorer para conectar-se ao controle do código-fonte
//   3. Use a janela de Saída para ver mensagens de saída do build e outras mensagens
//   4. Use a janela Lista de Erros para exibir erros
//   5. Ir Para o Projeto > Adicionar Novo Item para criar novos arquivos de código, ou Projeto > Adicionar Item Existente para adicionar arquivos de código existentes ao projeto
//   6. No futuro, para abrir este projeto novamente, vá para Arquivo > Abrir > Projeto e selecione o arquivo. sln
