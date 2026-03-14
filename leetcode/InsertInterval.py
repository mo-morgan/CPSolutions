class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        if not intervals:
            return [newInterval]
        # if the interval overlaps with any existing interval
        #  - we must merge the intervals into a new interval
        n = len(intervals)
        start_new, end_new = newInterval[0], newInterval[1]

        # since the array of intervals is sorted
        # we can binary search to find where to place the new interval
        #  1. find where to place start_new
        #   binary search on where to merge start_new
        found_index_left = -1
        left, right = 0, n-1
        while left <= right:
            mid = left + ((right - left) // 2)
            start, end = intervals[mid][0], intervals[mid][1]
            # find whether start_new belongs in this interval
            # there are 3 cases
            # 1. it's to the left of this interval
            #   - we binary search on the left
            # 2. it's to the right of this interval
            #   - we binary search on the right
            # 3. it's in this interval
            #   - we stop with the correct interval 
            if start_new < start:
                right = mid - 1
            elif start_new > end:
                left = mid + 1
            else:
                # start < start_new < end
                # in this case, we don't need to change the interval but just store the index
                found_index_left = mid
                break
        if found_index_left == -1:
            # we want the max of (left, right) because in the case where we need to change the start of an interval, we will always need to change the start of the later interval.
            found_index_left = max(left, right)

        found_index_right = -1
        left, right = 0, n-1
        while left <= right:
            mid = left + ((right - left) // 2)
            start, end = intervals[mid][0], intervals[mid][1]

            if end_new > end:
                left = mid + 1
            elif end_new < start:
                right = mid - 1
            else:
                found_index_right = mid
                break
        if found_index_right == -1:
            found_index_right = min(left, right)
        
        # first deal with the edge cases where the new interval needs to be inserted
        if min(found_index_left, found_index_right) < 0:
            intervals.insert(0, newInterval)
        elif max(found_index_right, found_index_left) >= n:
            intervals.append(newInterval)
        elif start_new > intervals[found_index_left][1] and end_new < intervals[found_index_right][0]:
            intervals.insert(found_index_left, [newInterval])

        else:
        # merge the intervals
            if start_new < intervals[found_index_left][0]:
                # need to replace start
                if end_new > intervals[found_index_right][1]:
                    # need to replace end
                    intervals[found_index_left:found_index_right + 1] = [[start_new, end_new]]
                else:
                    intervals[found_index_left:found_index_right + 1] = [[start_new, intervals[found_index_right][1]]]
                    
            else:
                # don't need to change start
                if end_new > intervals[found_index_right][1]:
                    # need to replace end
                    intervals[found_index_left:found_index_right + 1] = [[intervals[found_index_left][0], end_new]]
                    
                else: 
                    intervals[found_index_left:found_index_right + 1] = [[intervals[found_index_left][0], intervals[found_index_right][1]]]

        return intervals
