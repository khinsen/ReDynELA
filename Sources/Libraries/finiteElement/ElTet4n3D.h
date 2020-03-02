/***************************************************************************
 *                                                                         *
 *  DynELA Project                                                         *
 *                                                                         *
 *  (c) Copyright 1997-2006                                                *
 *                                                                         *
 *      Equipe C.M.A.O                                                     *
 *      Laboratoire Genie de production                                    *
 *      Ecole Nationale d'Ingenieurs de Tarbes                             *
 *      BP 1629 - 65016 TARBES cedex                                       *
 *                                                                         *
 *                                                                         *
 *  Main Author: Olivier PANTALE                                           *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 **************************************************************************/

// begin date : /03/2002

/*
  Class ElTet4n3D definition
  Element tetraedrique 3D a 4 noeuds pour analyse thermomecanique
*/

//#ifndef __Element_h__

#ifndef __ElTet4n3D_h__
#define __ElTet4n3D_h__

#define Name_ElTet4n3D "ElTet4n3D"

#include <Element3D.h>
class Element3D;

/**
*/
/** @dia:pos 148.8,188.8 */
/** @dia:route Element3D;v,147.95,178,184.851,160.95,188.8 */
class ElTet4n3D : public Element3D
{

public:
  /** @dia:route 3,12;h,148.8,189.5,146.75,223.85,16.75,143.3,41.8 */
  static const ElementData elementData;

public:
  // constructeurs
  ElTet4n3D(Indice No_ = 1);
  ElTet4n3D(const ElTet4n3D &el);
  ~ElTet4n3D();

  // fonction de manipulation
  Indice numberOfUnderIntegrationPoints()
  {
    return 1;
  }

  // fonctions de calcul
  Real getLength(); // calcule et renvoie la longueur caracteristique
  Real getVolume();
  // Boolean getUnderIntegrPointCoords (Indice, Vec3D & coords, Real& weight) ;
  void getShapeFunctionAtPoint(Vector &N, const Vec3D &point) const;
  void getDerShapeFunctionAtPoint(Matrix &N, const Vec3D &point);
  void computeGlob2Loc();
  void glob2Loc(const Vec3D &point, Vec3D &local);
  //void getIntgtoNodes(Vector& N,const Vec3D& point) const;
};

#endif