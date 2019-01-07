//***********************************************************
// Autor: F. Bruno Duarte
// Em: 07/01/2019
//***********************************************************

#ifndef FILA_H
#define FILA_H

#include <istream>
#include <assert.h>

// definição estrutura NoFila
template<class Type>
struct NoFila {
	Type info;
	NoFila<Type> *prox;
};

template<class Type>
class Fila {
public:
	Fila(){
		inicio = NULL;
		final = NULL;
	}

	void enqueue(const Type&);
	void dequeue();
	Type front() const;
	Type back() const;

	bool isEmpty() const{ return inicio == NULL; }
	
	const int size();
	void print();
	bool search(const Type&);
	void clear();
	
	~Fila(){ clear(); }
private:
	NoFila<Type> *inicio;
	NoFila<Type> *final;
};

// insere um elemento na fila
template<class Type>
void Fila<Type>::enqueue(const Type& i){
	NoFila<Type> *novo = new NoFila<Type>();
	novo->info = i;
	novo->prox = NULL;

	if(inicio == NULL){
		inicio = novo;
		final = novo;
	} else {
		final->prox = novo;
		final = final->prox;
	}
}

// remove um elemento da fila
template<class Type>
void Fila<Type>::dequeue(){
	NoFila<Type> *temp;

	if(!isEmpty()){
		temp = inicio;
		inicio = inicio->prox;

		delete temp;

		if(inicio == NULL)
			final = NULL;
	}
	else
		std::cout << "Impossível remover de uma lista vazia" 
			<< std::endl;
}

// retorna o início da fila
template<class Type>
Type Fila<Type>::front() const {
	assert(inicio != NULL);
	return inicio->info;
}

// retorna o final da fila
template<class Type>
Type Fila<Type>::back() const {
	assert(final != NULL);
	return final->info;
}

// retorna o tamanho da fila
template<class Type>
const int Fila<Type>::size(){
	if(inicio == NULL)
		return 0;
	int cont = 0;
	NoFila<Type> *p = inicio;
	while(p != NULL){
		cont++;
		p = p->prox;
	}
	return cont;
}

// imprime a fila
template<class Type>
void Fila<Type>::print(){
	Fila<Type> temp;
	
	while(size() != 0){
		temp.enqueue(front());
		dequeue();
	}
	
	while(temp.size() != 0){
		enqueue(temp.front());
		std::cout << temp.front() << " ";
		temp.dequeue();
	}
	std::cout << std::endl;
}

// procura um elemento na fila
template<class Type>
bool Fila<Type>::search(const Type& i){
	Fila<Type> temp;
	bool result = false;
	while(!isEmpty()){
		temp.enqueue(front());
		if(front() == i){
			result = true;
		}
		dequeue();
	}
	while (!isEmpty()){
		enqueue(temp.front());
		temp.dequeue();
	}
	return result;
}

// apaga toda a fila
template<class Type>
void Fila<Type>::clear(){
	NoFila<Type> *temp;

	while(inicio != NULL){
		temp = inicio;
		inicio = inicio->prox;
		delete temp;
	}

	final = NULL;
}

#endif
