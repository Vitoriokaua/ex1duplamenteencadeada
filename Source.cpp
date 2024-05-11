/* Faça uma função que receba duas listas encadeadas e as concatene.
A primeira lista deverá então possuir todos os elementos,
enquanto a segunda ficará vazia. Analise os casos especiais
(uma das duas listas, ou ambas, estando vazias).

*/

#include <iostream>

using namespace std;

struct Nolista
{
	int dado;
	Nolista* prox;
	Nolista* ant;


};

Nolista* Criar_lista() {
	return NULL;
}
void inserir_final(Nolista*& l, int dado) {
	Nolista* novo = new Nolista;
	novo->dado = dado;
	novo->ant = NULL;
	novo->prox = NULL;

	if (l == NULL)
	{
		l = novo;
	}
	else
	{
		Nolista* p = l;
		while (p->prox != NULL)
		{
			p = p->prox; 
		}
		p->prox = novo;
		novo->ant = p; 
	}
}


void imprimir(Nolista* l) {
	Nolista* p = l;
	while (p != NULL)
	{
		cout << p->dado << " ";
		p = p->prox;
	}
}

Nolista* juntar(Nolista*& l, Nolista*& l2) {
	if (l == NULL)
	{
		return l2;
	}
	else if (l2 == NULL)
	{
		return l;
	}

	Nolista* p = l;
	while (p->prox != NULL)
	{
		p = p->prox;
	}
	p->prox = l2;
	l2->ant = p;

	return l;



}









int main() {
	Nolista* lista = Criar_lista();
	Nolista* lista2 = Criar_lista();

	int n;
	cout << "informe um numero: (-1 ,para!) ";
	cin >> n;
	while (n != -1)
	{
		inserir_final(lista, n);
		cout << "informe um numero : (-1, para!)";
		cin >> n;
	}

	cout << endl;
	int n2;
	cout << "informe um numero: (-1 ,para!) ";
	cin >> n2;
	while (n2 != -1)
	{
		inserir_final(lista2, n2);
		cout << "informe um numero : (-1, para!)";
		cin >> n2;
	}

	cout << "antes de concatenar " << endl;
	cout << "lista1: " << endl;
	imprimir(lista);

	cout << endl;

	cout << "lista 2:" << endl;

	imprimir(lista2);

	Nolista* concatenou = juntar(lista, lista2);

	
	cout << "depois de conactenar: " << endl;
	imprimir(concatenou);




}