//#include "action.h"
//
//Action* Action::create(string type, string data, Store* store, int id, Movie* movie) {
//	if (type == "B") {
//		return new Borrow(data,store,id,movie);
//	}
//else if (type == "R") {
//		return new Return(data,1,store,id, movie);
//	}
//else if (type == "I") {
//		return new Inventory(data, store);
//	}
//else if (type == "H") {
//		return new History(data, store, id);
//	}
//	else {
//	return nullptr;
//	}
//}