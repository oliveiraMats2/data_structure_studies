#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nifti1.h"

typedef float MY_DATATYPE;

#define MIN_HEADER_SIZE 348
#define NII_HEADER_SIZE 352


int main(){
	nifti_1_header hdr;
	FILE *fp;

	char *hdr_file = "/mnt/arquivos_linux/A_master_degree/research_miclab/MateusOliveira_MSc/data/DTI_images/100206_3T_Diffusion_preproc-20220803T224721Z-001/100206_3T_Diffusion_preproc/100206/T1w/Diffusion/data.nii.gz";

	fp = fopen(hdr_file, "r");
	if(fp==NULL){
		fprintf(stderr, "\nError opening header file %s \n", hdr_file);
		exit(1);
	}

	fread(&hdr, MIN_HEADER_SIZE, 1, fp);
	fprintf(stderr, "\n%s header information:",hdr_file);
	fprintf(stderr, "\nXYZT dimensions: %d %d %d %d",hdr.dim[1],hdr.dim[2],hdr.dim[3],hdr.dim[4]);
	fprintf(stderr, "\nDatatype code and bits/pixel: %d %d",hdr.datatype,hdr.bitpix);
	fprintf(stderr, "\nScaling slope and intercept: %.6f %.6f",hdr.scl_slope,hdr.scl_inter);
	fprintf(stderr, "\nByte offset to data in datafile: %ld",(long)(hdr.vox_offset));
	fprintf(stderr, "\n");

}
