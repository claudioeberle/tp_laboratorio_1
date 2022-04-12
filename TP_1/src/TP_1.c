
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "tp1.h"

int main() {

	setbuf(stdout, NULL);


	int opcion;
	int flagCalculos;

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

	opcion=0;
	flagCalculos=0;
	kms=0;
	precioAA=0;
	precioLatam=0;




	do{

		switch (menu(kms, precioAA, precioLatam)){


			case 1:

				ingresoKms(pKms);

				break;


			case 2:

				aerolinea = submenuAerolinea();

				ingresoPrecios (aerolinea, pPrecioAA, pPrecioLatam);

				break;


			case 3: // calcular costos

				if (validarDatosParaCalculo(kms, precioAA, precioLatam)){

					calcularCostos(kms, precioAA, btc, pDebitoAA, pCreditoAA, pBitcoinAA, pUnitarioAA);
					calcularCostos(kms, precioLatam, btc, pDebitoLatam, pCreditoLatam, pBitcoinLatam, pUnitarioLatam);
					diferencia (precioLatam, precioAA, pDiferenciaPrecio);
					flagCalculos = 1;
					break;
				}

				break;

			case 4:

				if (validacionCalculos(flagCalculos)){

				informes (kms, precioAA, precioLatam, debitoAA, debitoLatam, creditoAA, creditoLatam, bitcoinAA, bitcoinLatam, unitarioAA, unitarioLatam, diferenciaPrecio);
				opcion = continuar();
				kms =0;
				precioAA =0;
				precioLatam =0;
				flagCalculos =0;
				break;

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
				flagCalculos =0;
				opcion = continuar();
				break;


			case 6:

				opcion = 6;
				break;

			}


	}while(opcion != 6);

	printf("\n\n¡Hasta Luego!\n\n");
	printf("Gracias por utilizar el Sistema. \n\n");

	return 0;

}//main

