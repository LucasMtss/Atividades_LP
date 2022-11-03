#pragma once
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;
using std::vector;

class Texto
{
public:
	Texto() {
		texto = "";
		numeroLinhas = 0;
	}
	// Obt�m o texto.
	string getTexto() {
		return this->texto;
	}
	// Retorna o n�mero de linhas do texto.
	size_t getNumeroLinhas() {
		return numeroLinhas;
	}

	// Contabiliza o n�mero de \n para alterar o valor de numeroLinhas
	void atualizaNumeroLinhas() {
		string delimiter = "\n";
		vector<string> linhas{};
		string copiaTexto = texto;

		size_t pos;
		while ((pos = copiaTexto.find(delimiter)) != string::npos) {
			linhas.push_back(copiaTexto.substr(0, pos));
			copiaTexto.erase(0, pos + delimiter.length());
		}
		numeroLinhas = linhas.size();
	}

	// Adiciona uma linha no texto. Cada linha � terminada com o caractere de nova linha ('\n').
	void adicionar(const string& linha) {
		texto.append(linha + "\n");
		atualizaNumeroLinhas();
	}
	// Obt�m a capacidade atual de armazenamento de caracteres do texto.
	size_t capacidade() {
		return texto.capacity();
	}
	// Obt�m o tamanho do texto, ou seja, o n�mero atual de caracteres do texto.
	size_t tamanho() {
		return texto.size();
	}
	/* Pesquisa pela primeira ocorr�ncia de uma string no texto.
	* Retorna o n�mero da linha do texto em caso de sucesso, se n�o retorna string::npos. */
	size_t pesquisar(const string& string) {
		return texto.find(string);
	}
	/* Altera uma linha do texto por uma nova linha.
	* Retorna true se a linha atual foi localizada e substitu�da, se n�o retorna false. */
	bool alterar(const string& linhaAtual, const string& linhaNova) {
		if (pesquisar(linhaAtual) == string::npos)
			return false;
		texto.replace(pesquisar(linhaAtual), linhaAtual.size(), linhaNova);
		return true;
	}
	/* Altera uma linha do texto identificada pelo seu n�mero. Considere a primeira linha igual a um.
	* Retorna true se a linha atual foi localizada e substitu�da, se n�o retorna false. */
	bool alterar(const string& linhaAtual, unsigned numeroLinha) {
		string delimiter = "\n";
		vector<string> linhas{};
		string copiaTexto = texto;

		size_t pos;
		while ((pos = copiaTexto.find(delimiter)) != string::npos) {
			linhas.push_back(copiaTexto.substr(0, pos));
			copiaTexto.erase(0, pos + delimiter.length());
		}
		if (numeroLinha > linhas.size() + 1)
			return false;
		linhas[numeroLinha - 1] = linhaAtual;

		texto = "";
		for (const auto& linha : linhas) {
			texto.append(linha + "\n");
		}
	}
	// Obt�m uma linha do texto de acordo com o seu n�mero. Considere a primeira linha igual a um.
	string obterLinha(unsigned numeroLinha) {
		string delimiter = "\n";
		vector<string> linhas{};
		string copiaTexto = texto;

		size_t pos;
		while ((pos = copiaTexto.find(delimiter)) != string::npos) {
			linhas.push_back(copiaTexto.substr(0, pos));
			copiaTexto.erase(0, pos + delimiter.length());
		}

		if (numeroLinha > linhas.size() > 1)
			return "Linha inv�lida!";
		return linhas[numeroLinha - 1];
	}
	// Apaga todo o texto.
	void excluir() {
		texto = "";
		numeroLinhas = 0;
	}

private:
	string texto; // Representa todas as linhas do texto.
	size_t numeroLinhas; // N�mero atual de linhas do texto.
};

