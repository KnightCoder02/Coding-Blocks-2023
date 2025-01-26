const Products = require('../models/products');

module.exports.getAdminHome = (req, res, next) => {
    res.render('admin/home');
}

module.exports.postProductsAdd = async (req, res, next) => {
    const {name, price, description, imageUrl, seller, category} = req.body;
    try{
        await Products.create({
            name, 
            price, 
            description, 
            imageUrl, 
            seller,
            category
        });
        res.redirect('/admin/products/all');
    }
    catch(err){
        res.send(err);
    }
}

module.exports.getProductsAdd = (req, res, next) => {
    res.render('admin/add-product');
}

module.exports.getProductsAll = async (req, res, next) => {
    const products = await Products.find();
    console.log(products);
    let data = {};
    
    products.forEach(product => {
        let arr = data[product.category] || [];
        arr.push(product);
        data[product.category] = arr;
    })
    res.render('admin/products-list', {
        products:data
    });
}

module.exports.postProductsUpdate = async (req, res, next) => {
    const {name, price, description, imageUrl, seller, id, category} = req.body;
    try{
        let product = await Products.findById(id);
        product.name = name;
        product.price = price;
        product.description = description;
        product.imageUrl = imageUrl;
        product.seller = seller;
        product.category = category;
        await product.save();
        res.redirect('/admin/products/all');
    }
    catch(err){
        res.send(err);
    }
}

module.exports.getProductsUpdate = async (req, res, next) => {
    const {id} = req.params;
    try{
        const product = await Products.findById(id);
        res.render('admin/update-product', {product});
    }
    catch(err){
        next(err);
    }
}

module.exports.getProductsDelete = async (req, res, next) => {
    const {id} = req.params;
    try{
        let product = await Products.deleteOne({_id: id});
        res.redirect('/admin/products/all');
    }
    catch(err){
        res.send(err);
    }
}