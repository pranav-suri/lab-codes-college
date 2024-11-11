import mongoose from "mongoose";
const uri = "mongodb://localhost:27017/test";

const kittySchema = new mongoose.Schema({
    name: String,
});
const Kitten = mongoose.model("Kitty", kittySchema);
await mongoose.connect(uri, );

const fluffy = new Kitten({ name: "fluffy" });
await fluffy.save();
const kittens = await Kitten.find();
console.log(kittens);
