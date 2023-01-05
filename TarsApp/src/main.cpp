#include <Tars/Tars.h>

int main() {
	Tars tars{"Tars App"};

	while (!tars.shouldClose()) {
		tars.pollEvents();
	}
}
