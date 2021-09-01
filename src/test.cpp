#include <iostream>
#include <chrono>
#include "D:/GIT/surge/src/position.h"
#include <cassert>
class TestWrapper {
private:
	static void testPerft() {
		Position p;
		Position::set("r3k2r/p1ppqpb1/bn2pnp1/3PN3/1p2P3/2N2Q1p/PPPBBPPP/R3K2R w KQkq -", p);//Kiwipete
		auto moveCount = TestWrapper::perft<WHITE>(p,4);
		assert(moveCount == 4085603 && "Something is wrong444!!!");

	}
	template<Color Us>
	static unsigned long long perft(Position& p, unsigned int depth) {
		int nmoves;
		unsigned long long nodes = 0;
		MoveList<Us> list(p);
		if (depth == 1) return (unsigned long long) list.size();
		for (Move move : list) {
			p.play<Us>(move);
			nodes += perft<~Us>(p, depth - 1);
			p.undo<Us>(move);
		}
		return nodes;
	}


public:
	static void runAllTests() {
		testPerft();
	}
};