// O(n^2)
func beautifulSubstrings(s string, k int) int64 {
	// pre process
	yl := make([]int, len(s))
	fl := make([]int, len(s))
	for i := 0; i < len(s); i++ {
		if s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' {
			yl[i] = 1
		} else {
			fl[i] = 1
		}
	}
	for i := 1; i < len(s); i++ {
		yl[i] += yl[i-1]
		fl[i] += fl[i-1]
	}
	//fmt.Println("yl:", yl)
	//fmt.Println("fl:", fl)

	ret := 0
	for i := 0; i < len(s); i++ {
		for j := i; j < len(s); j++ {
			if isBeautiful(yl, fl, i, j, k) {
				ret += 1
			}
		}
	}
	return int64(ret)
}

// O(1)
func isBeautiful(yl []int, fl []int, start int, end int, k int) bool {
	start_y := 0
	start_f := 0
	if start > 0 {
		start_y = yl[start-1]
	}
	if start > 0 {
		start_f = fl[start-1]
	}
	y_num := yl[end] - start_y
	f_num := fl[end] - start_f
	if y_num == f_num && (y_num*f_num)%k == 0 {
		return true
	}
	return false
}