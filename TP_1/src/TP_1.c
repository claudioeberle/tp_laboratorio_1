
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "tp1.h"

int main() {

	setbuf(stdout, NULL);


	int opcion=0;
	int flagCalculos=0;

	char aerolinea;

	float kms=0;
	float precioAA=0;
	float precioLatam=0;
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




	do{

		switch (menu(kms, precioAA, precioLatam)){


			case 1:

				ingresoKms(&kms);

				break;


			case 2:

				aerolinea = submenuAerolinea();

				ingresoPrecios (aerolinea, &precioAA, &precioLatam);

				break;


			case 3: // calcular costos

				if (validarDatosParaCalculo(kms, precioAA, precioLatam)){

					calcularCostos(kms, precioAA, btc, &debitoAA, &creditoAA, &bitcoinAA, &unitarioAA);
					calcularCostos(kms, precioLatam, btc, &debitoLatam, &creditoLatam, &bitcoinLatam, &unitarioLatam);
					diferencia (precioLatam, precioAA, &diferenciaPrecio);
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
				calcularCostos(kms, precioAA, btc, &debitoAA, &creditoAA, &bitcoinAA, &unitarioAA);
				calcularCostos(kms, precioLatam, btc, &debitoLatam, &creditoLatam, &bitcoinLatam, &unitarioLatam);
				diferencia (precioLatam, precioAA, &diferenciaPrecio);
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

