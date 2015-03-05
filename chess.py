# -*- coding: utf-8 -*-

'''
REVISE AS THIS IS NOT WHAT IS HAPPENING
Before building the application I want to ensure I have a way to test for correctness.  I also want an easy way for the tests to be written and also that the tests are easy to understand and that any errors are clearly visible.  I have also been a bit cheesy here and found that utf-8 has characters for chess pieces and also the squares.  I could assert by the board location but this would not be as easy to see so I am going to  output an actual representation of the board.  Although I do not want to assert on the board location eplicitly i.e. A1, H8 I do want to use these to address which of the squares I want to put a piece so that the representation of the board which is outputted and asserted against is expected.  To achieve this I am going to build a Board Harness which will allow me to place a specific piece on a specific square using the location as a rank and file index.  Ranks are the rows of a chess board so 1-8 and files are the columns so an example is A1 or H8
'''

import unittest

class BoardHarness:

	def __init__(self, board=None):
		self.indexes = {"A":2,"B":4,"C":6,"D":8,"E":10,"F":12,"G":13,"H":14}
		self.pieces = {
			"w_k": u"♔",
			"w_q": u"♕",
			"w_r": u"♖",
			"w_b": u"♗",
			"w_kn": u"♘",
			"w_p": u"♙",
			"b_k": u"♚",
			"b_q": u"♛",
			"b_r": u"♜",
			"b_b": u"♝",
			"b_kn": u"♞",
			"b_p": u"♟",
		}	
		if board is None:
			self.board = u"  A B C D E F G H \n\
8 □ ■ □ ■ □ ■ □ ■\n\
7 ■ □ ■ □ ■ □ ■ □\n\
6 □ ■ □ ■ □ ■ □ ■\n\
5 ■ □ ■ □ ■ □ ■ □\n\
4 □ ■ □ ■ □ ■ □ ■\n\
3 ■ □ ■ □ ■ □ ■ □\n\
2 □ ■ □ ■ □ ■ □ ■\n\
1 ■ □ ■ □ ■ □ ■ □"
		else:
			self.board = board

	def new_board(self, square, piece):
		string_rank_length = 18
		square_file = square[0]
		square_rank = int(square[1])
		
		square_file_index = self.indexes[square_file]
		square_rank_index = 8 - square_rank + 1

		location = square_file_index +  (square_rank_index * string_rank_length) + 1
		
		new_board = u""
		for index, val in enumerate(self.board):
			if index == location:
				new_board += piece
			else:
				new_board += self.board[index]

		return new_board

	def set(self,piece, square):
		piece = self.pieces[piece]
		board = self.new_board(square, piece)
		return BoardHarness(board)

	def __unicode__(self):
		return self.board

class TestBoardHarness(unittest.TestCase):
	def test_putting_white_king_on_a1(self):
		expected = u"  A B C D E F G H \n\
8 □ ■ □ ■ □ ■ □ ■\n\
7 ■ □ ■ □ ■ □ ■ □\n\
6 □ ■ □ ■ □ ■ □ ■\n\
5 ■ □ ■ □ ■ □ ■ □\n\
4 □ ■ □ ■ □ ■ □ ■\n\
3 ■ □ ■ □ ■ □ ■ □\n\
2 □ ■ □ ■ □ ■ □ ■\n\
1 ♔ □ ■ □ ■ □ ■ □"
		harness = BoardHarness()
		result = harness.set("w_k","A1")
		print(unicode(result))
		self.assertEquals(unicode(result), expected)

	def test_represents_64_bit_integer_in_visual_form(self):
		pass


if __name__ == "__main__":
	unittest.main()

