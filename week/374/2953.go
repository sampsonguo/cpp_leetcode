func minimumAddedCoins(coins []int, target int) int {
	sort.Sort(sort.IntSlice(coins))
	//fmt.Println(coins)
	t := 1 // 1 ~ target
	p := 0 // pointer for coins
	ret := 0
	for t <= target { // 未完成目标
		if p >= len(coins) || t < coins[p] {
			t *= 2
			ret++
		} else if p <= len(coins) && t == coins[p] {
			t *= 2
			p++
		} else if p <= len(coins) && t > coins[p] {
			t += coins[p]
			p++
		}
	}
	return ret
}