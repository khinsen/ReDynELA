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

// begin date :
// revision date :

/*
	Class ExplicitSolver definition
*/

#ifndef __ExplicitSolver_h__
#define __ExplicitSolver_h__

#include <upFemSolver.h>

#include <Solver.h>
class Domain;

/*!
  \file ExplicitSolver.h
  \brief fichier .h de d�finition des solveurs �l�ments finis
  \ingroup femExplicitSolver

  Ce fichier sert � la d�finition de la classe ExplicitSolver.

  \author Olivier PANTALE
  \version 1.0.0
  \date 1997-2004
*/

/*!
  \class ExplicitSolver ExplicitSolver.h
  \brief Classe de d�finition et de manipulation des solveurs �l�ments finis.
  \ingroup femExplicitSolver

  Cette classe sert � d�finir et � manipuler les solveurs disponibles au niveau d'un domaine. Elle contient toutes les d�finitions de base concernant la gestion des temps de simulation (incr�ment de temps, temps de d�but, de fin ...) ainsi que la gestion compl�te des incr�ments.

  \author Olivier PANTALE
  \version 1.0.0
  \date 1997-2004
*/
/** @dia:pos 233.8,43.8 */
/** @dia:route Solver;v,247.45,42,39.25,241.05,43.8 */
class ExplicitSolver : public Solver
{

public:
  // constructor
  ExplicitSolver();
  ExplicitSolver(const ExplicitSolver &X);
  ~ExplicitSolver();

  // member functions
  void solve(Real upTime);
  void computeForces();
  void computePredictions();
  void updateGrid();
  void computeStrains();
  void computeConstitutive();
  void computeStress();
  void computeState();
  void computeMass();
  void computeEnergy();
  void computeMomentum();
  void computeTemperatures();
  void computeCorrections();
  void scanInterfaces();
  void computeContactForces();
  void updateTime();
  const char *Name() { return "ExplicitSolver"; }
};

#endif
