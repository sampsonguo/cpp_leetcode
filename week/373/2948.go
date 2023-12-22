func lexicographicallySmallestArray(nums []int, limit int) []int {

	// sort
	nums2 := make([]int, len(nums))
	copy(nums2, nums)
	sort.Ints(nums2)

	// store sorted slices
	sortedSlices := make([][]int, 0)

	start := 0
	for i := 1; i < len(nums2); i++ {
		if nums2[i]-nums2[i-1] <= limit {
			continue
		} else {
			sortedSlices = append(sortedSlices, nums2[start:i])
			start = i
		}
	}
	sortedSlices = append(sortedSlices, nums2[start:])
	//fmt.Println(sortedSlices)

	// map: nums -> slices index
	nums2Index := make(map[int]int)
	for i := 0; i < len(sortedSlices); i++ {
		for j := 0; j < len(sortedSlices[i]); j++ {
			nums2Index[sortedSlices[i][j]] = i
		}
	}
	pointers := make([]int, len(sortedSlices))

	// replace slices into positions
	for i := 0; i < len(nums); i++ {
		idx := nums2Index[nums[i]]
		nums[i] = sortedSlices[idx][pointers[idx]]
		pointers[idx]++
	}

	return nums
}