/* Module chaine.c

   Ecrit par P. Baerlocher.
*/
#include <math.h>
#include <GL/glu.h>
#include "chaine.h"
#include "graphic.h"


static int chaine_calcule_angles (float l1,
								  float l2,
								  float x,
								  float y,
								  float *alpha,
								  float *beta);

static float chaine_rayon_min (float l1,
							   float l2);

static float chaine_rayon_max (float l1,
							   float l2);

static void  chaine_dessine (float l1,
							 float l2,
							 float alpha,
							 float beta);

static void chaine_dessine_limites (float l1,
									float l2);
                             
/* ---------------------------------------------------------------
   Serie 19: met à jour la structure CHAINE pointée par p.
   Cela comprend les angles alpha et beta pour atteindre 
   (ou essayer d'atteindre) le but (x,y) mémorisé dans la structure.
   le champ att est mis à 1 si le but est atteignable, ou 0 sinon.
   ---------------------------------------------------------------
*/
  
void chaine_update(CHAINE *p)
{
	/* à compléter série 19 */
}

/*--------------------------------------------------*/
/* serie19: rassemble le dessin de tous les éléments
 * que l'on peut dessiner à partir de la structure
 * de donnée CHAINE
*/

void chaine_display(CHAINE chain)
{ 
	/* à compléter série 19 */
}

/* ------------------------------------------------------
   Cette fonction calcule les angles alpha et beta
   pour atteindre (ou essayer d'atteindre) un but (x,y).
   Elle retourne 1 si le but est atteignable, ou 0 sinon.
   Dans tous les cas, les angles alpha et beta sont calcules.
   ------------------------------------------------------
*/
static int chaine_calcule_angles (float l1,
                           float l2,
                           float x,
                           float y,
                           float *alpha,
                           float *beta)

{ float r = sqrt (x*x + y*y);

  if (r > chaine_rayon_max (l1, l2))
  {
    *alpha = atan2 (y, x);
    *beta  = 0;

    return BUT_PAS_ATTEINT;
  }
  else
  if (r < chaine_rayon_min (l1, l2))
  {
    if (l1 < l2)
      *alpha = atan2 (y, x) + M_PI;
    else
      *alpha = atan2 (y, x);

    *beta  = M_PI;

    return BUT_PAS_ATTEINT;
  }
  else
  {
    if (r > 0.)
    {
      *alpha = atan2 (y, x) + acos ((r*r + l1*l1 - l2*l2) / (2.*l1*r));
      *beta  = M_PI + acos ((l1*l1 + l2*l2 - r*r) / (2.*l1*l2));
    }
    else
    {
      *alpha = 0.;
      *beta = M_PI;
    }

    return BUT_ATTEINT;
  }
}

/* -----------------------------------------------------
   Cette fonction calcule le rayon minimal en dessous
   duquel un but ne pourra pas etre atteint (limite
   inferieure de l'espace atteignable par l'effecteur).
   -----------------------------------------------------
*/
static float chaine_rayon_min (float l1,
                        float l2)
{ 
  return fabs(l1-l2);
}

/* -----------------------------------------------------
   Cette fonction calcule le rayon maximal en dessus
   duquel un but ne pourra pas etre atteint (limite
   superieure de l'espace atteignable par l'effecteur).
   -----------------------------------------------------
*/
static float chaine_rayon_max (float l1,
                        float l2)
{ 
  return l1+l2;
}

/* -----------------------------------------------------
   Affiche la chaine articulee, a partir de ses
   parametres.
   -----------------------------------------------------
*/
static void chaine_dessine (float l1,
                     float l2,
                     float alpha,
                     float beta)
{
  float px = l1 * cos (alpha),
    py = l1 * sin (alpha);
  float qx = px + l2 * cos (alpha+beta),
    qy = py + l2 * sin (alpha+beta);
  
  graphic_set_color3f (.2, .8, 1.);   
  graphic_set_line_width(3.);
  
  graphic_draw_segment (0., 0., px, py);
  graphic_draw_segment (px, py, qx, qy);
  
  graphic_draw_circle (0., 0., 0.2, GRAPHIC_FILLED);
  graphic_draw_circle (px, py, 0.2, GRAPHIC_FILLED);
  
  graphic_set_line_width(1.);
}


/* -----------------------------------------------------
   Affiche les limites de l'espace atteignable par
   l'effecteur de la chaine articulee.
   -----------------------------------------------------
*/

static void chaine_dessine_limites (float l1,
                             float l2)

{ float grey_col [] = { 0.1, 0.1, 0.1 },
	black_col [] = { 0, 0., 0. },
	border_col [] = { 0.8, 0.8, 0.8 };

  graphic_set_color3fv(grey_col);

  graphic_draw_circle (0., 0., chaine_rayon_max (l1, l2), GRAPHIC_FILLED);

  graphic_set_color3fv(black_col);

  graphic_draw_circle (0., 0., chaine_rayon_min (l1, l2), GRAPHIC_FILLED);

  graphic_set_color3fv(border_col);

  graphic_draw_circle (0., 0., chaine_rayon_min (l1, l2), GRAPHIC_EMPTY);

  graphic_draw_circle (0., 0., chaine_rayon_max (l1, l2), GRAPHIC_EMPTY);
}
