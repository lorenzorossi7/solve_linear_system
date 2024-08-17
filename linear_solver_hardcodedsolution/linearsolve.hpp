/*The function implemented in this file calculates the solution of the linear system of equations A X=B 
under the assumption that A is an 8x8 dimensional matrix with the last column given by A17=A27=A37=A47=A57=A67=0 (but A77!=0).
The array B gets overwritten and contains the solution on exit.*/

#ifndef LINEARSOLVE_HPP_
#define LINEARSOLVE_HPP_

#include "det_and_sol_comps/determinant.hpp"
#include "det_and_sol_comps/sol_comp0.hpp"
#include "det_and_sol_comps/sol_comp1.hpp"
#include "det_and_sol_comps/sol_comp2.hpp"
#include "det_and_sol_comps/sol_comp3.hpp"
#include "det_and_sol_comps/sol_comp4.hpp"
#include "det_and_sol_comps/sol_comp5.hpp"
#include "det_and_sol_comps/sol_comp6.hpp"
#include "det_and_sol_comps/sol_comp7_part1.hpp"
#include "det_and_sol_comps/sol_comp7_part2.hpp"
#include "det_and_sol_comps/sol_comp7_part3.hpp"
#include "det_and_sol_comps/sol_comp7_part4.hpp"
#include "det_and_sol_comps/sol_comp7_part5.hpp"
#include "det_and_sol_comps/sol_comp7_part6.hpp"
#include "det_and_sol_comps/sol_comp7_part7.hpp"
#include "det_and_sol_comps/sol_comp7_part8.hpp"


typedef double data_t;


void linear_solve_and_update_rhs(const int& N, data_t *A, data_t *B) {

   data_t A00=*(A+0);
   data_t A01=*(A+1);
   data_t A02=*(A+2);
   data_t A03=*(A+3);
   data_t A04=*(A+4);
   data_t A05=*(A+5);
   data_t A06=*(A+6);

   data_t A10=*(A+8);
   data_t A11=*(A+9);
   data_t A12=*(A+10);
   data_t A13=*(A+11);
   data_t A14=*(A+12);
   data_t A15=*(A+13);
   data_t A16=*(A+14);

   data_t A20=*(A+16);
   data_t A21=*(A+17);
   data_t A22=*(A+18);
   data_t A23=*(A+19);
   data_t A24=*(A+20);
   data_t A25=*(A+21);
   data_t A26=*(A+22);

   data_t A30=*(A+24);
   data_t A31=*(A+25);
   data_t A32=*(A+26);
   data_t A33=*(A+27);
   data_t A34=*(A+28);
   data_t A35=*(A+29);
   data_t A36=*(A+30);

   data_t A40=*(A+32);
   data_t A41=*(A+33);
   data_t A42=*(A+34);
   data_t A43=*(A+35);
   data_t A44=*(A+36);
   data_t A45=*(A+37);
   data_t A46=*(A+38);

   data_t A50=*(A+40);
   data_t A51=*(A+41);
   data_t A52=*(A+42);
   data_t A53=*(A+43);
   data_t A54=*(A+44);
   data_t A55=*(A+45);
   data_t A56=*(A+46);

   data_t A60=*(A+48);
   data_t A61=*(A+49);
   data_t A62=*(A+50);
   data_t A63=*(A+51);
   data_t A64=*(A+52);
   data_t A65=*(A+53);
   data_t A66=*(A+54);

   data_t A70=*(A+56);
   data_t A71=*(A+57);
   data_t A72=*(A+58);
   data_t A73=*(A+59);
   data_t A74=*(A+60);
   data_t A75=*(A+61);
   data_t A76=*(A+62);
   data_t A77=*(A+63);


   data_t B0=*(B+0);
   data_t B1=*(B+1);
   data_t B2=*(B+2);
   data_t B3=*(B+3);
   data_t B4=*(B+4);
   data_t B5=*(B+5);
   data_t B6=*(B+6);
   data_t B7=*(B+7);

   data_t detA;
   calc_det(
         A00,A01,A02,A03,A04,A05,A06,
         A10,A11,A12,A13,A14,A15,A16,
         A20,A21,A22,A23,A24,A25,A26,
         A30,A31,A32,A33,A34,A35,A36,
         A40,A41,A42,A43,A44,A45,A46,
         A50,A51,A52,A53,A54,A55,A56,
         A60,A61,A62,A63,A64,A65,A66,
         A70,A71,A72,A73,A74,A75,A76,A77,detA);

   calc_sol_comp0(
         A00,A01,A02,A03,A04,A05,A06,
         A10,A11,A12,A13,A14,A15,A16,
         A20,A21,A22,A23,A24,A25,A26,
         A30,A31,A32,A33,A34,A35,A36,
         A40,A41,A42,A43,A44,A45,A46,
         A50,A51,A52,A53,A54,A55,A56,
         A60,A61,A62,A63,A64,A65,A66,
         A70,A71,A72,A73,A74,A75,A76,A77,detA,
         B0,B1,B2,B3,B4,B5,B6,B7,
         B);
   calc_sol_comp1(
         A00,A01,A02,A03,A04,A05,A06,
         A10,A11,A12,A13,A14,A15,A16,
         A20,A21,A22,A23,A24,A25,A26,
         A30,A31,A32,A33,A34,A35,A36,
         A40,A41,A42,A43,A44,A45,A46,
         A50,A51,A52,A53,A54,A55,A56,
         A60,A61,A62,A63,A64,A65,A66,
         A70,A71,A72,A73,A74,A75,A76,A77,detA,
         B0,B1,B2,B3,B4,B5,B6,B7,
         B);
   calc_sol_comp2(
         A00,A01,A02,A03,A04,A05,A06,
         A10,A11,A12,A13,A14,A15,A16,
         A20,A21,A22,A23,A24,A25,A26,
         A30,A31,A32,A33,A34,A35,A36,
         A40,A41,A42,A43,A44,A45,A46,
         A50,A51,A52,A53,A54,A55,A56,
         A60,A61,A62,A63,A64,A65,A66,
         A70,A71,A72,A73,A74,A75,A76,A77,detA,
         B0,B1,B2,B3,B4,B5,B6,B7,
         B);
   calc_sol_comp3(
         A00,A01,A02,A03,A04,A05,A06,
         A10,A11,A12,A13,A14,A15,A16,
         A20,A21,A22,A23,A24,A25,A26,
         A30,A31,A32,A33,A34,A35,A36,
         A40,A41,A42,A43,A44,A45,A46,
         A50,A51,A52,A53,A54,A55,A56,
         A60,A61,A62,A63,A64,A65,A66,
         A70,A71,A72,A73,A74,A75,A76,A77,detA,
         B0,B1,B2,B3,B4,B5,B6,B7,
         B);
   calc_sol_comp4(
         A00,A01,A02,A03,A04,A05,A06,
         A10,A11,A12,A13,A14,A15,A16,
         A20,A21,A22,A23,A24,A25,A26,
         A30,A31,A32,A33,A34,A35,A36,
         A40,A41,A42,A43,A44,A45,A46,
         A50,A51,A52,A53,A54,A55,A56,
         A60,A61,A62,A63,A64,A65,A66,
         A70,A71,A72,A73,A74,A75,A76,A77,detA,
         B0,B1,B2,B3,B4,B5,B6,B7,
         B);
   calc_sol_comp5(
         A00,A01,A02,A03,A04,A05,A06,
         A10,A11,A12,A13,A14,A15,A16,
         A20,A21,A22,A23,A24,A25,A26,
         A30,A31,A32,A33,A34,A35,A36,
         A40,A41,A42,A43,A44,A45,A46,
         A50,A51,A52,A53,A54,A55,A56,
         A60,A61,A62,A63,A64,A65,A66,
         A70,A71,A72,A73,A74,A75,A76,A77,detA,
         B0,B1,B2,B3,B4,B5,B6,B7,
         B);
   calc_sol_comp6(
         A00,A01,A02,A03,A04,A05,A06,
         A10,A11,A12,A13,A14,A15,A16,
         A20,A21,A22,A23,A24,A25,A26,
         A30,A31,A32,A33,A34,A35,A36,
         A40,A41,A42,A43,A44,A45,A46,
         A50,A51,A52,A53,A54,A55,A56,
         A60,A61,A62,A63,A64,A65,A66,
         A70,A71,A72,A73,A74,A75,A76,A77,detA,
         B0,B1,B2,B3,B4,B5,B6,B7,
         B);
   calc_sol_comp7_part1(
         A00,A01,A02,A03,A04,A05,A06,
         A10,A11,A12,A13,A14,A15,A16,
         A20,A21,A22,A23,A24,A25,A26,
         A30,A31,A32,A33,A34,A35,A36,
         A40,A41,A42,A43,A44,A45,A46,
         A50,A51,A52,A53,A54,A55,A56,
         A60,A61,A62,A63,A64,A65,A66,
         A70,A71,A72,A73,A74,A75,A76,A77,detA,
         B0,B1,B2,B3,B4,B5,B6,B7,
         B);
   calc_sol_comp7_part2(
         A00,A01,A02,A03,A04,A05,A06,
         A10,A11,A12,A13,A14,A15,A16,
         A20,A21,A22,A23,A24,A25,A26,
         A30,A31,A32,A33,A34,A35,A36,
         A40,A41,A42,A43,A44,A45,A46,
         A50,A51,A52,A53,A54,A55,A56,
         A60,A61,A62,A63,A64,A65,A66,
         A70,A71,A72,A73,A74,A75,A76,A77,detA,
         B0,B1,B2,B3,B4,B5,B6,B7,
         B);
   calc_sol_comp7_part3(
         A00,A01,A02,A03,A04,A05,A06,
         A10,A11,A12,A13,A14,A15,A16,
         A20,A21,A22,A23,A24,A25,A26,
         A30,A31,A32,A33,A34,A35,A36,
         A40,A41,A42,A43,A44,A45,A46,
         A50,A51,A52,A53,A54,A55,A56,
         A60,A61,A62,A63,A64,A65,A66,
         A70,A71,A72,A73,A74,A75,A76,A77,detA,
         B0,B1,B2,B3,B4,B5,B6,B7,
         B);
   calc_sol_comp7_part4(
         A00,A01,A02,A03,A04,A05,A06,
         A10,A11,A12,A13,A14,A15,A16,
         A20,A21,A22,A23,A24,A25,A26,
         A30,A31,A32,A33,A34,A35,A36,
         A40,A41,A42,A43,A44,A45,A46,
         A50,A51,A52,A53,A54,A55,A56,
         A60,A61,A62,A63,A64,A65,A66,
         A70,A71,A72,A73,A74,A75,A76,A77,detA,
         B0,B1,B2,B3,B4,B5,B6,B7,
         B);
   calc_sol_comp7_part5(
         A00,A01,A02,A03,A04,A05,A06,
         A10,A11,A12,A13,A14,A15,A16,
         A20,A21,A22,A23,A24,A25,A26,
         A30,A31,A32,A33,A34,A35,A36,
         A40,A41,A42,A43,A44,A45,A46,
         A50,A51,A52,A53,A54,A55,A56,
         A60,A61,A62,A63,A64,A65,A66,
         A70,A71,A72,A73,A74,A75,A76,A77,detA,
         B0,B1,B2,B3,B4,B5,B6,B7,
         B);
   calc_sol_comp7_part6(
         A00,A01,A02,A03,A04,A05,A06,
         A10,A11,A12,A13,A14,A15,A16,
         A20,A21,A22,A23,A24,A25,A26,
         A30,A31,A32,A33,A34,A35,A36,
         A40,A41,A42,A43,A44,A45,A46,
         A50,A51,A52,A53,A54,A55,A56,
         A60,A61,A62,A63,A64,A65,A66,
         A70,A71,A72,A73,A74,A75,A76,A77,detA,
         B0,B1,B2,B3,B4,B5,B6,B7,
         B);
   calc_sol_comp7_part7(
         A00,A01,A02,A03,A04,A05,A06,
         A10,A11,A12,A13,A14,A15,A16,
         A20,A21,A22,A23,A24,A25,A26,
         A30,A31,A32,A33,A34,A35,A36,
         A40,A41,A42,A43,A44,A45,A46,
         A50,A51,A52,A53,A54,A55,A56,
         A60,A61,A62,A63,A64,A65,A66,
         A70,A71,A72,A73,A74,A75,A76,A77,detA,
         B0,B1,B2,B3,B4,B5,B6,B7,
         B);
   calc_sol_comp7_part8(
         A00,A01,A02,A03,A04,A05,A06,
         A10,A11,A12,A13,A14,A15,A16,
         A20,A21,A22,A23,A24,A25,A26,
         A30,A31,A32,A33,A34,A35,A36,
         A40,A41,A42,A43,A44,A45,A46,
         A50,A51,A52,A53,A54,A55,A56,
         A60,A61,A62,A63,A64,A65,A66,
         A70,A71,A72,A73,A74,A75,A76,A77,detA,
         B0,B1,B2,B3,B4,B5,B6,B7,
         B);

}


#endif // LINEARSOLVE_HPP_
