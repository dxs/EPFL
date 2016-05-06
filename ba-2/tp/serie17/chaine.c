/* Module chaine.c

   Ecrit par P. Baerlocher.
*/

#include <math.h>
#include "chaine.h"
#include "graphic.h"

#define BUT_ATTEINT     1
#define BUT_PAS_ATTEINT 0

/*----------------------------------------*/

int chaine_calcule_angles (float l1,
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

/*----------------------------------------*/

float chaine_rayon_min (float l1,
                        float l2)

{ return 0; /* A completer (serie 17) */
}

/*----------------------------------------*/

float chaine_rayon_max (float l1,
                        float l2)

{ return 0; /* A completer (serie 17) */
}

/*----------------------------------------*/

void chaine_dessine (float l1,
                     float l2,
                     float alpha,
                     float beta)

{ /* A completer (serie 17) */
}

/*----------------------------------------*/

void chaine_dessine_limites (float l1,
                             float l2)

{ 

  graphic_set_color3f (0.1, 0.1, 0.1);

  graphic_draw_circle (0., 0., chaine_rayon_max (l1, l2), GRAPHIC_FILLED);

  graphic_set_color3f (0., 0., 0.);

  graphic_draw_circle (0., 0., chaine_rayon_min (l1, l2), GRAPHIC_FILLED);

  graphic_set_color3f (0.8, 0.8, 0.8);

  graphic_draw_circle (0., 0., chaine_rayon_min (l1, l2), GRAPHIC_EMPTY);

  graphic_draw_circle (0., 0., chaine_rayon_max (l1, l2), GRAPHIC_EMPTY);
}
