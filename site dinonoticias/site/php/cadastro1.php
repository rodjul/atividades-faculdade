<?php

//arquivo upload
    $arquivo = $_FILES['arquivo'];
	
	$tamaho_maximo=$_POST['MAX_SIZE_FILE'];		
			
	$tamanho_maximo = 200000; // em bytes
	$tipos_aceitos = array(	"image/gif",
							"image/png",
							"image/bmp",
							"image/jpeg");
	//Validar o arquivo enviado
	if($arquivo['error'] != 0) {
		echo '<p style="font-weight:bold;color:red">Erro no Upload do arquivo<br>';
		switch($arquivo['error']) {
		case  UPLOAD_ERR_INI_SIZE:
						echo 'O Arquivo excede o tamanho máximo permitido.';
						break;
		case UPLOAD_ERR_FORM_SIZE:
				echo 'O Arquivo enviado é muito grande.';
				break;
		case  UPLOAD_ERR_PARTIAL:
				echo 'O upload não foi completo.';
				break;
		case UPLOAD_ERR_NO_FILE:
				echo 'Nenhum arquivo foi informado para upload.';	
				break;
		}
		echo	'</p>';
	  	exit;
	}
	if($arquivo['size']==0 OR $arquivo['tmp_name']==NULL) {
		echo '<p style="font-weight:bold;color:red">Nenhum arquivo enviado.</p>';
		exit;
	}
	if($arquivo['size']>$tamanho_maximo) {
		echo '<p style="font-weight:bold;color:red">O Arquivo enviado é muito grande
			(Tamanho Máximo = ' . $tamaho_maximo . ' bytes).</p>';
		exit;
	}
	if(array_search($arquivo['type'],$tipos_aceitos)===FALSE) {
		echo '<p style="font-weight:bold;color:red">O Arquivo enviado é do tipo (' . 
				$arquivo['type'] . ') não aceito para upload. 
				Os tipos aceitos são:	</p>';
		echo '<pre>';
		print_r($tipos_aceitos);
		echo '</pre>';
		exit;
	}

	// Agora podemos copiar o arquivo enviado
	if (!file_exists('imagem/usuarios/'.$nome)) {
					mkdir('imagem/usuarios/'.$nome, 0777, true);
				}
    $destino = 'imagem/usuarios/'.$nome.'/' . $arquivo['name'];
    $resultado = mysqli_query($conexao, "INSERT INTO usuarios(nome, login, senha, imagem) VALUES ('".$nome."','".$login."',".$senha.",'".$destino."')") or die("Não foi possível executar a SQL:".mysqli_error($conexao));
    
//$resultado = mysqli_query($conexao, "INSERT INTO bancosite(nome, email, senha, foto) VALUES ('".$nome."','".$email."',".$senha.",'".$arquivo['name']."')") or die("Não foi possível executar a SQL:".mysqli_error($conexao));

    if($resultado == TRUE){
       $resultadotrue = "<p class='cadastro'>Cadastro feito com sucesso!</p>";
    }

	
	if(move_uploaded_file($arquivo['tmp_name'],$destino)) {
        
		// Tudo Ok, mostramos os dados 
        //echo  '<p style="font-weight:bold;color:navy">';
        //echo 'O Arquivo foi carregado com sucesso para ' .$destino.'!</p>';
        //echo "<img src='$destino' border=0>";
        include "php/cabecalho-e-menu.php";
        echo "<section id='principal'><section id='noticias'>";
        echo $resultadotrue;
        echo "<a class='cadastro' href='index.html'>Clique aqui para voltar</a>";
        echo "</section></section>";
        include "php/footer.php";
     
    }
    		
        
	
	else {
		echo '<p style="font-weight:bold;color:red">Ocorreu um erro durante o upload</p>';
	}

?>
