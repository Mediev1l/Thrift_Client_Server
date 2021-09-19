namespace cpp MessengerNamespace

service Messenger {
	// Takes message and returns response
	string sendMessage(1:string text)
}
