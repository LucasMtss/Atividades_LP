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
	// Obtém o texto.
	string getTexto() {
		return this->texto;
	}
	// Retorna o número de linhas do texto.
	size_t getNumeroLinhas() {
		return numeroLinhas;
	}

	// Contabiliza o número de \n para alterar o valor de numeroLinhas
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

	// Adiciona uma linha no texto. Cada linha é terminada com o caractere de nova linha ('\n').
	void adicionar(const string& linha) {
		texto.append(linha + "\n");
		atualizaNumeroLinhas();
	}
	// Obtém a capacidade atual de armazenamento de caracteres do texto.
	size_t capacidade() {
		return texto.capacity();
	}
	// Obtém o tamanho do texto, ou seja, o número atual de caracteres do texto.
	size_t tamanho() {
		return texto.size();
	}
	/* Pesquisa pela primeira ocorrência de uma string no texto.
	* Retorna o número da linha do texto em caso de sucesso, se não retorna string::npos. */
	size_t pesquisar(const string& string) {
		return texto.find(string);
	}
	/* Altera uma linha do texto por uma nova linha.
	* Retorna true se a linha atual foi localizada e substituída, se não retorna false. */
	bool alterar(const string& linhaAtual, const string& linhaNova) {
		if (pesquisar(linhaAtual) == string::npos)
			return false;
		texto.replace(pesquisar(linhaAtual), linhaAtual.size(), linhaNova);
		return true;
	}
	/* Altera uma linha do texto identificada pelo seu número. Considere a primeira linha igual a um.
	* Retorna true se a linha atual foi localizada e substituída, se não retorna false. */
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
	// Obtém uma linha do texto de acordo com o seu número. Considere a primeira linha igual a um.
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
			return "Linha inválida!";
		return linhas[numeroLinha - 1];
	}
	// Apaga todo o texto.
	void excluir() {
		texto = "";
		numeroLinhas = 0;
	}

private:
	string texto; // Representa todas as linhas do texto.
	size_t numeroLinhas; // Número atual de linhas do texto.
};

