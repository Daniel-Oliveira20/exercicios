#include <iostream>
using namespace std;

int main() {
    // Declaração de variáveis
    string nome;
    float p1, p2, media;
    
    // Solicitação dos dados
    cout << "Digite o nome do aluno: ";
    getline(cin, nome);
    
    cout << "Digite a nota da P1: ";
    cin >> p1;
    
    cout << "Digite a nota da P2: ";
    cin >> p2;
    
    // Cálculo da média
    media = (p1 + p2) / 2;
    
    // Exibição dos resultados
    cout << "A média do aluno " << nome << " é " << media << endl;
    
    if (media >= 6) {
        cout << "O aluno " << nome << " está aprovado!" << endl;
    } else {
        cout << "O aluno " << nome << " está reprovado." << endl;
    }
    
    return 0;
}
