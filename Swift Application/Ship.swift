protocol virtualMethods{
	func printShip()
}
class Ship : virtualMethods, CustomStringConvertible {
	var name:String		
	var year:String

	//Constuctor
	init(name:String, year:String){
		self.name = name
		self.year = year
	}
	//Get functions and its return type
	func getName() -> String {
		return name
	}
	func getYear() -> String {
		return year
	}
	func setName(name:String){
		self.name = name
	}
	func setYear(year:String){
		self.year = year
	}
	//print Function
	func printShip(){
		print("Ship's Name: \(name)")
		print("Ship's Year: \(year)")
	}
	//Overloading the print functions from the CustomStringConvertible extension
	var description: String {
        return ("Ship's Name: \(name)\nShip's Year: \(year)")
    }
}

class CruiseShip : Ship {
	var passengers:Int
	init(name:String, year:String, passengers:Int){
		self.passengers = passengers
		super.init(name:name, year:year)
	}
	override init(name:String, year:String){
		self.passengers = 0
		super.init(name:name, year:year)
	}
	func getPassengers() -> Int{
		return passengers
	}
	func setPassengers(passengers:Int){
		self.passengers = passengers
	}
	override func printShip(){
		print("Cruise Ship's Name: \(name)")
		print("Passengers on Board: \(passengers)")
	}
	override var description: String {
        return ("Cruise Ship's Name: \(name)\nCruise Ship's Year: \(year)\nPassengers on Board: \(passengers)")
    }
	static func +(left: CruiseShip, right: Int){
		left.passengers += right	
	}
    postfix static func ++(thisShip: CruiseShip){
		thisShip.passengers += 1
	}
	prefix static func ++(thisShip: CruiseShip){
		thisShip.passengers += 1
	}
}

class CargoShip : Ship {
	var capacity : Int
	init(name : String, year : String, capacity : Int) {
		self.capacity = capacity
		super.init(name:name, year : year)
	}
	override init(name : String, year : String) {
		self.capacity = 0
			super.init(name:name, year : year)
	}
	func getCapacity() -> Int {
		return capacity
	}
	func setCapacity(capacity:Int) {
		self.capacity = capacity
	}
	override func printShip() {
		print("Cargo Ship's Name: \(name)")
		print("Capacity is at: \(capacity)")
	}
	override var description : String{
		return ("Cargo Ship's Name: \(name)\nCargo Ship's Year: \(year)\nCapacity is at: \(capacity)")
	}
}

precedencegroup Equivalence {
  higherThan: ComparisonPrecedence
  lowerThan: AdditionPrecedence
}
infix operator ✌️ : Equivalence
func ✌️(left: CargoShip, right: CruiseShip) -> CargoShip{ 
	let newname = left.name + " & " + right.name
	let newyear = left.year
	let newcapacity = left.capacity + right.passengers
    return CargoShip(name:newname, year:newyear, capacity:newcapacity)
}

print("N.Renella's & L.Guan's Ship")
print()

print("Problem 12 in the book...")
print("Creating a pointer array of ships with 2 Cruise Ships and 2 Cargo Ships(printing out with print function)...")
print()

var shipCollection = [CruiseShip(name:"Carnival Cruise", year:"1950", passengers:30000), CargoShip(name:"Big Tug Boat", year:"1898", capacity:2000), 
                      CruiseShip(name:"Norwegian Escape", year:"2015", passengers:4266),CargoShip(name:"SS Capella", year:"1972", capacity:110700)]

for ship in shipCollection{
	ship.printShip()
}

var cruiseShip1 = CruiseShip(name:"Norwegian Escape", year:"2015", passengers:4266)
var cargoShip1 = CargoShip(name:"SS Capella", year:"1972", capacity:110700)
var ship1 = Ship(name:"Black Pearl", year:"2003")

print("Testing the overloaded cout << operator with 3 different ships... ")
print("-------Cruise Ship-------")
print(cruiseShip1)
print("-------Cargo Ship-------")
print(cargoShip1)
print("----------Ship----------")
print(ship1)
print()

print("Adding 100 to Norwegian Escape capacity")
cruiseShip1 + 100
print(cruiseShip1)
print()

print("Using posfix increment on your ship...")
cruiseShip1++
print(cruiseShip1)
print()

print("Using prefix increment on your ship...")
++cruiseShip1
print(cruiseShip1)
print()

print("Now Testing our custom Operator...")
var NewCargoShip = cargoShip1 ✌️ cruiseShip1
print(NewCargoShip)

