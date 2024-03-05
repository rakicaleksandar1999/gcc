
void daxpy(float *vector1, float *vector2, int n, float fp_const){
	for (int i = 0; i < n; ++i)
		vector1[i] += fp_const * vector2[i];
}

void dgefa(float *vector, int m, int n, int l){
	for (int i = 0; i < n - 1; ++i){
		for (int j = i + 1; j < n; ++j){
			float t = vector[m * j + l];
			daxpy(&vector[m * i + i + 1],
                              &vector[m * j + i + 1], n - (i + 1), t);
		}
	}
}

int main(){
  return 0;
}
