#include <assert.h>
#include <math.h>
#include "analyze.h"
#include <stdlib.h>

//double x_arrary[10]{0,1,2,3,4,5,6,7,8,9};
// You can add other functions if you want to perform
// other calculations indepenent of these functions.
int count=0;
void data_init( data_t *p_this, double step_size ) {
    double *entries_ = NULL;
    p_this->entries_=(double *)malloc( 10*sizeof(double) );
    for(int i=0;i<10;i++){
      p_this->entries_[i]=0.0;

    }
    size_t k;


}

void data_destroy( data_t *p_this ) {
  free(p_this -> entries_);
}

void data_append( data_t *p_this, double new_value ) {
  if(count>9){//arrary满了 
    for(int i=0;i<9;i++){
      p_this->entries_[i]=p_this->entries_[i+1];
    }
      p_this->entries_[9]=new_value;
      // x_arrary[1] = 0.2;
  }else{//arrary未满
    p_this->entries_[count]=new_value;
    count++;
  }

  

  // for(int i=0;i<9;i++){
  //   p_this->entries_[i]=p_this->entries_[i+1];
  // }
  // p_this->entries_[9]=new_value;


  }  



double data_current( data_t *p_this ) {//APPROXIMATION
  double y = 0.0;
  double row_1[10]={0.022727272727273, 0.007575757575758, -0.003787878787879, -0.011363636363636, 
                    -0.015151515151515, -0.015151515151515, -0.011363636363636, -0.003787878787879, 
                    0.007575757575758, 0.022727272727273};
  double row_2[10]={0.259090909090909, 0.110606060606061, -0.003787878787879, -0.084090909090909, 
                    -0.130303030303030, -0.142424242424242, -0.120454545454545, -0.064393939393939,  
                    0.025757575757576,  0.150000000000000};
  double row_3[10]={0.618181818181818, 0.381818181818182, 0.190909090909091, 0.045454545454545, 
                    -0.054545454545455, -0.109090909090909, -0.118181818181818, -0.081818181818182, 
                    0.000000000000001,  0.127272727272727};

  double a_2=0.0;
  double a_1=0.0;
  double a_0=0.0;

  for(int i=0; i< 10; ++i){
    a_2 += row_1[i] * p_this->entries_[i];
    a_1 += row_2[i] * p_this->entries_[i];
    a_0 += row_3[i] * p_this->entries_[i];
  }

  y = (-9)*(-9)*a_2 + a_1 * (-9) + a_0;
  return y;
}

double data_next( data_t *p_this ) {//APPROXIMATION
  double y = 0.0;
    double row_1[10]={0.022727272727273, 0.007575757575758, -0.003787878787879, -0.011363636363636, 
                    -0.015151515151515, -0.015151515151515, -0.011363636363636, -0.003787878787879, 
                    0.007575757575758, 0.022727272727273};
  double row_2[10]={0.259090909090909, 0.110606060606061, -0.003787878787879, -0.084090909090909, 
                    -0.130303030303030, -0.142424242424242, -0.120454545454545, -0.064393939393939,  
                    0.025757575757576,  0.150000000000000};
  double row_3[10]={0.618181818181818, 0.381818181818182, 0.190909090909091, 0.045454545454545, 
                    -0.054545454545455, -0.109090909090909, -0.118181818181818, -0.081818181818182, 
                    0.000000000000001,  0.127272727272727};
  double a_2=0;
  double a_1=0;
  double a_0=0;

  for(int i=0; i< 10; ++i){
    a_2 += row_1[i] * p_this->entries_[i];
    a_1 += row_2[i] * p_this->entries_[i];
    a_0 += row_3[i] * p_this->entries_[i];
  }

  y = (-10.0)*(-10)*a_2 + a_1 * (-10.0) + a_0;
  return y;
 

}

