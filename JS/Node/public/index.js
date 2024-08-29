let products = [];
const form = document.getElementById('productForm');
let fetchurl = "http://localhost:12345/products" 

if (window.location.hostname !== 'localhost') {
    fetchurl = window.location.origin;
} 


const start = () => {
    fetch(fetchurl)
    .then(response => {
        if (!response.ok) {
            showNotification(response.message, "error");
        }
        return response.json();
    })
    .then(data => {
        showNotification(data.message);
        products = data.data;
        renderProducts(products)
    })
    .catch(e => {
        showNotification(e, "error");
    })
}

const showNotification= (message, type = 'success') => {
    const notification = document.createElement('div');

    notification.style.position = 'fixed';
    notification.style.bottom = '20px';
    notification.style.right = '20px';
    notification.style.padding = '15px 25px';
    notification.style.borderRadius = '8px';
    notification.style.boxShadow = '0 4px 12px rgba(0, 0, 0, 0.1)';
    notification.style.zIndex = '1000';
    notification.style.fontFamily = 'Arial, sans-serif';
    notification.style.display = 'flex';
    notification.style.alignItems = 'center';
    notification.style.justifyContent = 'space-between';
    notification.style.color = '#fff';
    notification.style.maxWidth = '300px';
    notification.style.transition = 'opacity 0.3s ease';

    if (type === 'success') {
        notification.style.backgroundColor = '#4CAF50';
    } else if (type === 'error') {
        notification.style.backgroundColor = '#F44336';
    }

    const messageText = document.createElement('span');
    messageText.textContent = message;

    const closeButton = document.createElement('span');
    closeButton.textContent = '×';
    closeButton.style.marginLeft = '20px';
    closeButton.style.cursor = 'pointer';
    closeButton.style.fontSize = '20px';
    closeButton.onclick = () => {
        notification.style.opacity = '0';
        setTimeout(() => {
            notification.remove();
        }, 300);
    };

    notification.appendChild(messageText);
    notification.appendChild(closeButton);

    document.body.appendChild(notification);

    setTimeout(() => {
        notification.style.opacity = '0';
        setTimeout(() => {
            notification.remove();
        }, 300);
    }, 5000);
}

const renderProducts = (productList) => {
    const productListElement = document.getElementById('productList');
    productListElement.innerHTML = '';

    productList.forEach(product => {
        const productHTML = `
            <div class="col mb-4">
                <div class="card product-card">
                    <img src="${product.url}" class="card-img-top" alt="${product.name}">
                    <div class="card-body">
                        <p class="product-title">${product.name}</p>
                        <p class="product-price">$${product.price + "$"}</p>
                    </div>
                </div>
            </div>
        `;
        productListElement.innerHTML += productHTML;
    });
}

form.addEventListener("submit", (event) => {
    event.preventDefault();

    const name = document.getElementById('productName').value;
    const price = parseFloat(document.getElementById('productPrice').value);
    const url = document.getElementById('url').value;

    const data = { name, price, url }
    
    fetch(fetchurl, {
        method: "POST",
        headers: {
            "Content-Type": "application/json"
        },
        body: JSON.stringify(data)
    })
    .then(response => {
        console.log(response);
    })
    .catch(e => {
        console.log(e);
    })
})

start()