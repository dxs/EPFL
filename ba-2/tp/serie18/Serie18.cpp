/****************************************************************************

Serie 18

****************************************************************************/

#include <stdlib.h>
#include <string.h>
#include <GL/glut.h>
#include <GL/glui.h>

namespace {
	char text[200] = "Salut!";

	/*pointeurs pour créer les objets de GLUI*/

	GLUI_Checkbox   *checkbox1;
	GLUI_Checkbox   *checkbox2;
	GLUI_Checkbox   *checkbox3;
	GLUI_Spinner    *spinner1;
	GLUI_Spinner    *spinner2;
	GLUI_EditText   *edittext;
	GLUI_RadioGroup *radio;
}
/**************************************** control_cb() *******************/
/* GLUI control callback                                                 */

void control_cb( int control )
{
  /********************************************************************
    imprimer la valeur du paramètre pour indiquer qui a produit l'appel.
    utiliser les fonctions de type get_int_val() ou get_float_val()
    plutôt que de créer des live variables.
    ********************************************************************/
}


/**************************************** main() ********************/
/*    inutile de créer des callback pour reshape et display
 *    car GLUI s'occupe automatiquement de redessiner la fenêtre
 *     contenant les widgets.
 * 
 *    remarque: dans cet état initial ce code compile ne fait
 *              qu'afficher un message d'accueil.
 * 
 *
*/
int main(int argc, char* argv[])
{
  // message d'accueil à enlever par la suite
	
  printf("\nA vous de compléter le code source Serie18.cpp\n\n");
	
  /****************************************/
  /*   Initialize GLUT and create window  */
  /****************************************/

  /****************************************/
  /*   register callback functions  */
  /****************************************/

  /****************************************/
  /* widgets GLUI */
  /****************************************/
  
  //Start Glut Main Loop
  
  return 0;
}
