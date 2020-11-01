class stack:
    def __init__(self):
        self.s = []
        self.length = 0
        self.notes = [] # to keep track of lazy updates
        
    def top(self):
        if self.length == 0:
            return 'EMPTY'
        return self.s[self.length - 1] + self.notes[self.length - 1]
        
    def push(self, v):
        self.length = self.length + 1
        self.s.append(v)
        self.notes.append(0)
        print(self.top())
    
    def pop(self):
        self.s.pop()
        self.length = self.length - 1
        if self.length - 1 >= 0:
            self.notes[self.length - 1] = self.notes[self.length - 1] + self.notes.pop()
        else:
            self.notes.pop()
        print(self.top())
    
    def inc(self, i, v):
        self.notes[i-1] = self.notes[i-1] + v
        print(self.top())

def superStack(operations):
    n = len(operations)
    i = 0
    s = stack()
    while i < n:
        op = operations[i].split()
        if op[0] == 'push':
            s.push(int(op[1]))
        elif op[0] == 'pop':
            s.pop()
        elif op[0] == 'inc':
            s.inc(int(op[1]), int(op[2]))
        
        i = i + 1