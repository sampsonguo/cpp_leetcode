func areSimilar(mat [][]int, k int) bool {
	for i := 0; i < len(mat); i++ {
		for j := 0; j < len(mat[i]); j++ {
			i2 := i
			j2 := j
			if i%2 == 0 { // 右移k
				j2 = (j + k) % len(mat[i])
			} else { // 左移k
				j2 = (j - k%len(mat[i]) + len(mat[i])) % len(mat[i])
			}
			if mat[i][j] != mat[i2][j2] {
				return false
			}
		}
	}
	return true
}