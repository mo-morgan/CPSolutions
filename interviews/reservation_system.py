import sys
from datetime import *

# ReservationSystem class to handle the ticketing system
class ReservationSystem:

    # TODO: keep track of issued tickets
    def __init__(self, N, S, K, hours, slots):
        self.is_open = False
        self.max_seats = N
        self.available_seats = N
        self.stay_time = S
        self.num_slots = K

        # self.issued_tickets is implemented as a queue to keep track of which ticket to call next
        self.issued_tickets = []

        # the opening hours of the restaurant in datetime format
        self.start_time, self.end_time = [datetime.strptime(x, '%H:%M') for x in hours.split("-")]

        # every seat has an estimated call time indicating when it's likely to be free
        self.available_slots = []
        for i in range(self.max_seats):
            self.available_slots.append(None)

    def handle_time_query(self, time, x):
        if x == 1:
            self.is_open = True
            self.available_seats = self.max_seats
        if x == self.num_slots + 1:
            self.is_open = False

    # assume that it is the earliest seat that we set to be available
    def handle_seat_available_query(self, D, time):
        if len(self.issued_tickets) == 0:
            self.available_seats += 1
            time = datetime.strptime(time, '%H:%M')
            self.set_available(time)
        else:
            self.call_ticket(D, time)

    def set_available(self, time):
        k = self.available_slots.pop()
        if k == None:
            self.available_slots.push(time)
        else:
            self.available_slots.push(time + timedelta(self.stay_time))
        

    def handle_issue_unspecified_ticket_query(self, D, time, ticket):
        if not self.satisfies_issuance_condition(time):
            print("%d %s Error: cannot issue %s" % (D, time, ticket))
        elif self.available_seats > 0:
            self.issue_ticket(ticket)
            self.call_ticket(D, time)
            self.available_seats -= 1
        else:
            self.issue_ticket(ticket)
            estimated_call_time = self.get_estimated_call_time(time)
            print("{:d} {:s} {:02d}:{:02d}".format(D, time, estimated_call_time.hour, estimated_call_time.minute))

    # Issuance condition is satisfied if
    # - the ticket is requested during opening hours
    # - the estimated call time is within opening hours
    def satisfies_issuance_condition(self, time):
        issue_time = datetime.strptime(time, '%H:%M')
        
        # if the issue time is at or after opening time
        #       and strictly before closing time 
        #       and its estimated call time is within open hours
        estimated_time = self.get_estimated_call_time(time)
        if issue_time >= self.start_time and issue_time < self.end_time and estimated_time < self.end_time:
            return True
        else:
            return False

    # issue a new ticket
    def issue_ticket(self, ticket):
        self.issued_tickets.append(ticket)

    # call_ticket does 2 jobs
    # - call the earliest ticket and print out the ticket number
    # - append the estimated leave time for the ticket
    def call_ticket(self, D, time):
        ticket = self.issued_tickets.pop(0)
        self.available_slots.pop()
        time1 = datetime.strptime(time, '%H:%M')
        self.available_slots.append(time1)

        # adding the typical stay time
        call_time = datetime.strptime(time, '%H:%M') + timedelta(minutes=self.stay_time)

        self.available_slots

        print("%d %s %s" % (D, time, ticket))

    # return the earliest estimated time
    def get_estimated_call_time(self, time):
        time = datetime.strptime(time, '%H:%M')
        estimated_time = self.available_slots[-1]
        if estimated_time == None:
            return time
        elif time > estimated_time:
            return time
        else:
            return estimated_time



def main(lines):
    info = lines[0].split()

    # 1 <= N <= 100, 5 <= S <= 120
    N, S = [int(x) for x in info[0:2]]

    # start <= opening_hours < closing
    opening_hours = info[2]

    # 1 <= K <= 20
    K = int(info[3])

    time_slots = []
    for i in range(4, K+4):
        time_slots.append(info[i])
    q = len(lines)

    system = ReservationSystem(N, S, K, opening_hours, time_slots)
    for i in range(1, q):
        line = lines[i].split()
        D = int(line[0])
        time = line[1]
        query_type = line[2]

        if query_type == 'time':
            x = int(line[3])
            system.handle_time_query(time, x)
        elif query_type == 'available':
            system.handle_seat_available_query(D, time)
        elif query_type == 'issue-unspecified':
            ticket = line[3]
            system.handle_issue_unspecified_ticket_query(D, time, ticket)
        else:
            print('No such query')



if __name__ == '__main__':
    lines = []
    for l in sys.stdin:
        lines.append(l.rstrip('\r\n'))
    main(lines)