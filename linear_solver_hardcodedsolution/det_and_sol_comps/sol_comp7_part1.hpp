#ifndef SOL_COMP7_PART1_HPP_
#define SOL_COMP7_PART1_HPP_


typedef double data_t;

void calc_sol_comp7_part1(
	const data_t& A00,const data_t& A01,const data_t& A02,const data_t& A03,const data_t& A04,const data_t& A05,const data_t& A06,
   const data_t& A10,const data_t& A11,const data_t& A12,const data_t& A13,const data_t& A14,const data_t& A15,const data_t& A16,
   const data_t& A20,const data_t& A21,const data_t& A22,const data_t& A23,const data_t& A24,const data_t& A25,const data_t& A26,
   const data_t& A30,const data_t& A31,const data_t& A32,const data_t& A33,const data_t& A34,const data_t& A35,const data_t& A36,
   const data_t& A40,const data_t& A41,const data_t& A42,const data_t& A43,const data_t& A44,const data_t& A45,const data_t& A46,
   const data_t& A50,const data_t& A51,const data_t& A52,const data_t& A53,const data_t& A54,const data_t& A55,const data_t& A56,
   const data_t& A60,const data_t& A61,const data_t& A62,const data_t& A63,const data_t& A64,const data_t& A65,const data_t& A66,
   const data_t& A70,const data_t& A71,const data_t& A72,const data_t& A73,const data_t& A74,const data_t& A75,const data_t& A76,const data_t& A77,const data_t& detA,
   const data_t& B0,const data_t& B1,const data_t& B2,const data_t& B3,const data_t& B4,const data_t& B5,const data_t& B6,const data_t& B7,
   data_t *B){

   *(B+7)=B7/A77;

}

#endif // SOL_COMP7_PART1_HPP_