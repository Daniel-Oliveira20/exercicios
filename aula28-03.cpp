#include <iostream>
using namespace std;

// definicao de tipo
struct NO {
	int valor;
	NO* prox;
};

NO* primeiro = NULL;

// headers
void menu();
void inicializar();
void exibirQuantidadeElementos();
void exibirElementos();
void inserirElemento();
void excluirElemento();
void buscarElemento();
NO* posicaoElemento(int numero);
//--------------------------


int main()
{
	menu();
}

void menu()
{
	int op = 0;
	while (op != 7) {
		system("cls"); // somente no windows
		cout << "Menu Lista Ligada";
		cout << endl << endl;
		cout << "1 - Inicializar Lista \n";
		cout << "2 - Exibir quantidade de elementos \n";
		cout << "3 - Exibir elementos \n";
		cout << "4 - Buscar elemento \n";
		cout << "5 - Inserir elemento \n";
		cout << "6 - Excluir elemento \n";
		cout << "7 - Sair \n\n";

		cout << "Opcao: ";
		cin >> op;

		switch (op)
		{
		case 1: inicializar();
			break;
		case 2: exibirQuantidadeElementos();
			break;
		case 3: exibirElementos();
			break;
		case 4: buscarElemento();
			break;
		case 5: inserirElemento();
			break;
		case 6: excluirElemento();
			break;
		case 7:
			return;
		default:
			break;
		}

		system("pause"); // somente no windows
	}
}

void inicializar()
{
	// se a lista já possuir elementos
// libera a memoria ocupada
	NO* aux = primeiro;
	while (aux != NULL) {
		NO* paraExcluir = aux;
		aux = aux->prox;
		free(paraExcluir);
	}

	primeiro = NULL;
	cout << "Lista inicializada \n";

}

void exibirQuantidadeElementos() {

	int nElementos = 0;
	NO* aux = primeiro;
	while (aux != NULL) {
		nElementos++;
		aux = aux->prox;
	}
	cout << "Quantidade de elementos: " << nElementos << endl;

}

void exibirElementos()
{
	if (primeiro == NULL) {
		cout << "Lista vazia \n";
		return;
	}
	else {
		cout << "Elementos: \n";
		NO* aux = primeiro;
		while (aux != NULL) {
			cout << aux->valor << endl;
			aux = aux->prox;
		}
	}
}

void inserirElemento()
{
    // aloca memoria dinamicamente para o novo elemento
    NO* novo = (NO*)malloc(sizeof(NO));
    if (novo == NULL)
    {
        return;
    }

    cout << "Digite o elemento: ";
    cin >> novo->valor;
    novo->prox = NULL;

    if (primeiro == NULL)
    {
        // lista vazia, o novo elemento é o primeiro
        primeiro = novo;
    }
    else
    {
        // encontra o local correto para inserir o novo elemento
        NO* anterior = NULL;
        NO* atual = primeiro;
        while (atual != NULL && atual->valor < novo->valor) {
            anterior = atual;
            atual = atual->prox;
        }
        if (atual != NULL && atual->valor == novo->valor) {
            free(novo);
            cout << "Elemento ja existe na lista" << endl;
            return;
        }
        if (anterior == NULL) {
            novo->prox = primeiro;
            primeiro = novo;
        }
        else {
            anterior->prox = novo;
            novo->prox = atual;
        }
    }
}

void excluirElemento()
{
	int numero;
    cout << "Digite o elemento a ser excluido: ";
    cin >> numero;
    
    NO* anterior = NULL;
    NO* atual = primeiro;

    while (atual != NULL && atual->valor != numero) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL) {
        cout << "Elemento nao encontrado na lista \n";
        return;
    }

    if (anterior == NULL) {
        primeiro = atual->prox;
    }
    else {
        anterior->prox = atual->prox;
    }

    free(atual);
    cout << "Elemento excluido da lista \n";
}

void buscarElemento()
{
	int valorBusca;
    cout << "Digite o elemento a ser buscado: ";
    cin >> valorBusca;

    NO* inicio = primeiro;
    NO* fim = NULL;
    while (inicio != fim) {
        NO* meio = inicio;
        int tamanho = 0;
        while (meio != fim) {
            meio = meio->prox;
            tamanho++;
        }
        meio = inicio;
        for (int i = 0; i < tamanho / 2; i++) {
            meio = meio->prox;
        }

        if (valorBusca == meio->valor) {
            cout << "Elemento encontrado" << endl;
            return;
        }
        else if (valorBusca < meio->valor) {
            fim = meio;
        }
        else {
            inicio = meio->prox;
        }
    }

    cout << "Elemento nao encontrado" << endl;
}
