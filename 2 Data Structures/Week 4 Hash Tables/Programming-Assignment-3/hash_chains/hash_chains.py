# python3

class Query:

    def __init__(self, query):
        self.type = query[0]
        if self.type == 'check':
            self.ind = int(query[1])
        else:
            self.s = query[1]


class QueryProcessor:
    _multiplier = 263
    _prime = 1000000007

    def __init__(self, bucket_count):
        self.bucket_count = bucket_count
        # store all strings in one list
        self.elems = [[] for _ in range(bucket_count)]

    def _hash_func(self, s):
        ans = 0
        for c in reversed(s):
            ans = (ans * self._multiplier + ord(c)) % self._prime
        return ans % self.bucket_count

    def write_search_result(self, was_found):
        print('yes' if was_found else 'no')

    def write_chain(self, chain):
        print(' '.join(chain))

    def read_query(self):
        return Query(input().split())

    def process_query(self, query):
        if query.type == "check":
            print(" ".join(self.elems[query.ind]))
            
        if query.type == "add":
            HashValue = self._hash_func(query.s)
            bucket = self.elems[HashValue]
            if query.s not in bucket:
                self.elems[HashValue] = [query.s] + bucket
                
        if query.type == "del":
            HashValue = self._hash_func(query.s)
            bucket = self.elems[HashValue]
            index = -1
            for i, s in enumerate(bucket):
                if query.s == s:
                    index = i
                if index > -1:
                    bucket.pop(index)
        
        if query.type == "find":
            HashValue = self._hash_func(query.s)
            bucket = self.elems[HashValue]
            result = "no" if query.s not in bucket else "yes"
            print(result)

    def process_queries(self):
        n = int(input())
        for i in range(n):
            self.process_query(self.read_query())

if __name__ == '__main__':
    bucket_count = int(input())
    proc = QueryProcessor(bucket_count)
    proc.process_queries()
