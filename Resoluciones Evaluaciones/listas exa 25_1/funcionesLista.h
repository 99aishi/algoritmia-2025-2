//
// Created by 999 on 9/21/2025.
//

#ifndef LISTAS_EXA_25_1_FUNCIONESLISTA_H
#define LISTAS_EXA_25_1_FUNCIONESLISTA_H

void construirLista(Lista & lista);
bool esListaVacia(const Lista &lista);
void insertarInicio(Lista &lista, const struct ElementoLista &elemento);
void insertarFinal(Lista &lista, const struct ElementoLista &elemento);
struct NodoLista *obtenerUltimo(Lista &lista);
#endif //LISTAS_EXA_25_1_FUNCIONESLISTA_H