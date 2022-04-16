
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "biblioteca_tp1.h"

int main() {

	setbuf(stdout, NULL);


	int salida;
	int flagCalculos;
	int flagReingreso;

	char aerolinea;

	float kms;
	float precioAA;
	float precioLatam;
	float btc=4606954.55;
	float debitoAA;
	float debitoLatam;
	float creditoAA;
	float creditoLatam;
	float bitcoinAA;
	float bitcoinLatam;
	float unitarioAA;
	float unitarioLatam;
	float diferenciaPrecio;

	int* pFlagReingreso = &flagReingreso;
	float* pKms = &kms;
 	float* pPrecioAA = &precioAA;
	float* pPrecioLatam = &precioLatam;
	float* pDebitoAA = &debitoAA;
	float* pDebitoLatam = &debitoLatam;
	float* pCreditoAA = &creditoAA;
	float* pCreditoLatam = &creditoLatam;
	float* pBitcoinAA = &bitcoinAA;
	float* pBitcoinLatam = &bitcoinLatam;
	float* pUnitarioAA = &unitarioAA;
	float* pUnitarioLatam = &unitarioLatam;
	float* pDiferenciaPrecio = &diferenciaPrecio;

	salida=0;
	flagCalculos=0;
	flagReingreso = 0;
	kms=0;
	precioAA=0;
	precioLatam=0;


	do{

		switch (menu(kms, precioAA, precioLatam)){

			case 1:

				if (kms){

					reIngresoKms (pKms);
				}
				else{

					ingresoKms(pKms);
				}

				break;

			case 2:

				aerolinea = submenuAerolinea();

				ingresoPrecios(aerolinea, pPrecioAA, pPrecioLatam, pFlagReingreso);

				if(flagReingreso){

					reingresoPrecios(aerolinea, pPrecioAA, pPrecioLatam);
					flagReingreso = 0;

				}

				break;

			case 3: // calcular costos

				if (validarDatosParaCalculo(kms, precioAA, precioLatam)){

					calcularCostos(kms, precioAA, btc, pDebitoAA, pCreditoAA, pBitcoinAA, pUnitarioAA);
					calcularCostos(kms, precioLatam, btc, pDebitoLatam, pCreditoLatam, pBitcoinLatam, pUnitarioLatam);
					diferencia (precioLatam, precioAA, pDiferenciaPrecio);
					flagCalculos = 1;
				}

				break;

			case 4:

				if (validacionCalculos(flagCalculos)){

					informes (kms, precioAA, precioLatam, debitoAA, debitoLatam, creditoAA, creditoLatam, bitcoinAA, bitcoinLatam, unitarioAA, unitarioLatam, diferenciaPrecio);
					salida = continuar();
					kms =0;
					precioAA =0;
					precioLatam =0;
					flagCalculos = 0;
				}

				break;


			case 5:

				kms = 7090;
				precioAA = 162965;
				precioLatam = 159339;
				calcularCostos(kms, precioAA, btc, pDebitoAA, pCreditoAA, pBitcoinAA, pUnitarioAA);
				calcularCostos(kms, precioLatam, btc, pDebitoLatam, pCreditoLatam, pBitcoinLatam, pUnitarioLatam);
				diferencia (precioLatam, precioAA, pDiferenciaPrecio);
				informes (kms, precioAA, precioLatam, debitoAA, debitoLatam, creditoAA, creditoLatam, bitcoinAA, bitcoinLatam, unitarioAA, unitarioLatam, diferenciaPrecio);
				kms =0;
				precioAA =0;
				precioLatam =0;
				flagCalculos = 0;
				salida = continuar();
				break;


			case 6:

				salida = 6;
				break;

			}


	}while(salida != 6);

	saludo();

	return 0;

}//main

